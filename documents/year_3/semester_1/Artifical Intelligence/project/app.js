// ========== EcoRoute Mobile AI System - JavaScript ========== //

// ========== CONFIGURATION ==========
const ADDRESSES = [
    "12 Jalan Wong Ah Fook", 
    "45 Persiaran Medini", 
    "88 Jalan Skudai", 
    "5 Jalan Trus",
    "23 Jalan Danga",
    "67 Jalan Austin"
];
const DEPOT = { x: 50, y: 80 };
const PRIORITY_THRESHOLD = 80;
const WARNING_THRESHOLD = 50;

// ========== STATE ==========
let bins = [];
let activeRoute = [];
let simulationInterval = null;
let predictiveMode = true;
let isWeekend = false;
let fuelSaved = 0;
let routeGenerated = false;

// Driver-specific state
let driverCurrentIndex = 0;
let driverShiftActive = false;
let collectedBins = [];
let totalRouteDistance = 0;

// Trip History state
let tripHistory = [];
let currentTripData = null;
let operationalOverrides = [];
let shiftStartTime = null;
let collectionTimestamps = [];

// Driver/Vehicle simulation data
const DRIVERS = [
    { id: 'DRV-001', name: 'Ahmad bin Hassan', vehicle: 'ECO-T01' },
    { id: 'DRV-002', name: 'Lim Wei Ming', vehicle: 'ECO-T02' },
    { id: 'DRV-003', name: 'Rajesh Kumar', vehicle: 'ECO-T03' }
];
let currentDriver = null;

// ========== INITIALIZATION ==========
function init() {
    generateBins();
    renderAllMaps();
    updateDate();
    updateStats();
    loadTripHistory();
    
    // Initial AI log
    setTimeout(() => {
        addAgentLog('🟢 System initialized', 'success');
        addAgentLog('📡 Connected to 12 IoT sensors', 'info');
        addAgentLog('🧠 Predictive model loaded', 'info');
    }, 500);
}

// ========== TRIP HISTORY FUNCTIONS ==========

function loadTripHistory() {
    const stored = localStorage.getItem('ecoroute_trip_history');
    if (stored) {
        try {
            tripHistory = JSON.parse(stored);
        } catch (e) {
            tripHistory = [];
        }
    }
    renderTripHistory();
}

function saveTripHistory() {
    localStorage.setItem('ecoroute_trip_history', JSON.stringify(tripHistory));
}

function renderTripHistory() {
    const listEl = document.getElementById('history-list');
    const emptyState = document.getElementById('history-empty-state');
    const totalCount = document.getElementById('total-trips-count');
    
    if (!listEl || !emptyState || !totalCount) return;
    
    totalCount.textContent = tripHistory.length;
    
    if (tripHistory.length === 0) {
        emptyState.style.display = 'block';
        // Remove any existing cards
        listEl.querySelectorAll('.history-card').forEach(el => el.remove());
        return;
    }
    
    emptyState.style.display = 'none';
    
    // Clear existing cards
    listEl.querySelectorAll('.history-card').forEach(el => el.remove());
    
    // Render trips (newest first)
    [...tripHistory].reverse().forEach((trip, idx) => {
        const card = createTripCard(trip, tripHistory.length - 1 - idx);
        listEl.appendChild(card);
    });
}

function createTripCard(trip, index) {
    const card = document.createElement('div');
    card.className = 'history-card rounded-3xl p-5';
    card.onclick = () => openTripDetail(index);
    
    const date = new Date(trip.timestamp);
    const dateStr = date.toLocaleDateString('en-GB', { day: 'numeric', month: 'short', year: 'numeric' });
    const timeStr = date.toLocaleTimeString('en-GB', { hour: '2-digit', minute: '2-digit' });
    
    const efficiencyClass = trip.efficiency >= 90 ? 'excellent' : trip.efficiency >= 75 ? 'good' : 'average';
    const efficiencyLabel = trip.efficiency >= 90 ? 'Excellent' : trip.efficiency >= 75 ? 'Good' : 'Average';
    
    card.innerHTML = `
        <div class="flex items-start justify-between mb-3">
            <div class="flex items-center gap-3">
                <div class="w-12 h-12 rounded-2xl bg-gradient-to-br from-slate-100 to-slate-200 flex items-center justify-center">
                    <i class="fa-solid fa-truck text-slate-600"></i>
                </div>
                <div>
                    <div class="font-bold text-slate-800">${trip.driverName}</div>
                    <div class="text-xs text-slate-500">${trip.vehicleId} • ${trip.driverId}</div>
                </div>
            </div>
            <span class="history-badge ${efficiencyClass}">${efficiencyLabel}</span>
        </div>
        
        <div class="flex items-center gap-2 text-xs text-slate-500 mb-3">
            <i class="fa-regular fa-calendar"></i>
            <span>${dateStr} at ${timeStr}</span>
            <span class="text-slate-300">•</span>
            <span>${trip.duration} min</span>
        </div>
        
        <div class="grid grid-cols-3 gap-2">
            <div class="bg-slate-50 rounded-xl p-2 text-center">
                <div class="text-sm font-bold text-slate-800">${trip.binsCollected}/${trip.totalBins}</div>
                <div class="text-[9px] text-slate-400 uppercase">Bins</div>
            </div>
            <div class="bg-emerald-50 rounded-xl p-2 text-center">
                <div class="text-sm font-bold text-emerald-600">${trip.fuelSaved}L</div>
                <div class="text-[9px] text-slate-400 uppercase">Saved</div>
            </div>
            <div class="bg-blue-50 rounded-xl p-2 text-center">
                <div class="text-sm font-bold text-blue-600">${trip.efficiency}%</div>
                <div class="text-[9px] text-slate-400 uppercase">Efficiency</div>
            </div>
        </div>
    `;
    
    return card;
}

function openTripDetail(index) {
    const trip = tripHistory[index];
    if (!trip) return;
    
    currentTripData = trip;
    
    // Populate detail view
    const date = new Date(trip.timestamp);
    document.getElementById('detail-trip-date').textContent = date.toLocaleDateString('en-GB', { 
        weekday: 'long', day: 'numeric', month: 'long', year: 'numeric' 
    });
    
    document.getElementById('detail-driver-name').textContent = trip.driverName;
    document.getElementById('detail-vehicle-id').textContent = `${trip.vehicleId} • ${trip.driverId}`;
    
    const efficiencyClass = trip.efficiency >= 90 ? 'excellent' : trip.efficiency >= 75 ? 'good' : 'average';
    const badge = document.getElementById('detail-efficiency-badge');
    badge.textContent = `${trip.efficiency}% Efficiency`;
    badge.className = `history-badge ${efficiencyClass}`;
    
    document.getElementById('detail-bins-count').textContent = `${trip.binsCollected}/${trip.totalBins}`;
    document.getElementById('detail-fuel-saved').textContent = `${trip.fuelSaved}L`;
    document.getElementById('detail-duration').textContent = `${trip.duration}m`;
    
    // Render route map
    renderTripRouteMap(trip);
    
    // Render timeline
    renderCollectionTimeline(trip);
    
    // Render overrides
    renderOperationalOverrides(trip);
    
    // Show overlay
    document.getElementById('trip-detail-overlay').classList.add('open');
}

function closeTripDetail() {
    document.getElementById('trip-detail-overlay').classList.remove('open');
    currentTripData = null;
}

function renderTripRouteMap(trip) {
    const svg = document.getElementById('detail-route-svg');
    svg.innerHTML = '';
    
    if (!trip.route || trip.route.length === 0) return;
    
    // Draw route path
    let pathD = `M ${trip.depot.x}% ${trip.depot.y}%`;
    trip.route.forEach(bin => {
        pathD += ` L ${bin.x}% ${bin.y}%`;
    });
    pathD += ` L ${trip.depot.x}% ${trip.depot.y}%`;
    
    const path = document.createElementNS('http://www.w3.org/2000/svg', 'path');
    path.setAttribute('d', pathD);
    path.setAttribute('fill', 'none');
    path.setAttribute('stroke', '#3b82f6');
    path.setAttribute('stroke-width', '2');
    path.setAttribute('stroke-linecap', 'round');
    path.setAttribute('stroke-linejoin', 'round');
    path.setAttribute('stroke-dasharray', '6,3');
    svg.appendChild(path);
    
    // Draw bin markers
    trip.route.forEach((bin, idx) => {
        const circle = document.createElementNS('http://www.w3.org/2000/svg', 'circle');
        circle.setAttribute('cx', `${bin.x}%`);
        circle.setAttribute('cy', `${bin.y}%`);
        circle.setAttribute('r', '6');
        circle.setAttribute('fill', bin.isPriority ? '#ef4444' : '#10b981');
        circle.setAttribute('stroke', 'white');
        circle.setAttribute('stroke-width', '2');
        svg.appendChild(circle);
    });
    
    // Draw depot
    const depot = document.createElementNS('http://www.w3.org/2000/svg', 'rect');
    depot.setAttribute('x', `${trip.depot.x - 4}%`);
    depot.setAttribute('y', `${trip.depot.y - 4}%`);
    depot.setAttribute('width', '8%');
    depot.setAttribute('height', '8%');
    depot.setAttribute('fill', '#f59e0b');
    depot.setAttribute('stroke', 'white');
    depot.setAttribute('stroke-width', '2');
    depot.setAttribute('rx', '2');
    svg.appendChild(depot);
}

function renderCollectionTimeline(trip) {
    const container = document.getElementById('detail-timeline');
    container.innerHTML = '';
    
    if (!trip.collections || trip.collections.length === 0) {
        container.innerHTML = '<p class="text-sm text-slate-400 italic">No collection data available</p>';
        return;
    }
    
    trip.collections.forEach((item, idx) => {
        const div = document.createElement('div');
        div.className = 'timeline-item pb-4';
        
        const time = new Date(item.timestamp);
        const timeStr = time.toLocaleTimeString('en-GB', { hour: '2-digit', minute: '2-digit' });
        
        div.innerHTML = `
            <div class="timeline-dot ${item.isPriority ? 'priority' : ''}"></div>
            <div class="bg-white rounded-xl p-3 shadow-sm border border-slate-100">
                <div class="flex items-center justify-between mb-1">
                    <span class="font-bold text-sm text-slate-800">Bin #${item.binId}</span>
                    <span class="text-xs text-slate-500">${timeStr}</span>
                </div>
                <p class="text-xs text-slate-500">${item.address}</p>
                <div class="flex items-center gap-2 mt-2">
                    <span class="text-xs px-2 py-0.5 rounded-full ${item.isPriority ? 'bg-red-100 text-red-600' : 'bg-emerald-100 text-emerald-600'}">
                        ${item.fillLevel}% Full
                    </span>
                </div>
            </div>
        `;
        
        container.appendChild(div);
    });
}

function renderOperationalOverrides(trip) {
    const container = document.getElementById('detail-overrides');
    container.innerHTML = '';
    
    if (!trip.overrides || trip.overrides.length === 0) {
        container.innerHTML = `
            <div class="bg-slate-50 rounded-xl p-4 text-center">
                <i class="fa-solid fa-check-circle text-emerald-500 text-xl mb-2"></i>
                <p class="text-sm text-slate-500">No operational overrides during this shift</p>
            </div>
        `;
        return;
    }
    
    trip.overrides.forEach(override => {
        const div = document.createElement('div');
        div.className = 'override-log-item rounded-xl p-3';
        
        const time = new Date(override.timestamp);
        const timeStr = time.toLocaleTimeString('en-GB', { hour: '2-digit', minute: '2-digit' });
        
        const icons = {
            'telemetry': 'fa-broadcast-tower',
            'seasonal': 'fa-calendar-week',
            'predictive': 'fa-brain'
        };
        
        const labels = {
            'telemetry': 'Live Telemetry',
            'seasonal': 'Seasonal Logic',
            'predictive': 'Predictive Mode'
        };
        
        div.innerHTML = `
            <div class="flex items-center gap-3">
                <div class="w-8 h-8 rounded-lg bg-white/10 flex items-center justify-center">
                    <i class="fa-solid ${icons[override.type] || 'fa-cog'} text-emerald-400 text-sm"></i>
                </div>
                <div class="flex-1">
                    <div class="text-xs font-bold text-white">${labels[override.type] || override.type}</div>
                    <div class="text-[10px] text-slate-400">${override.action}</div>
                </div>
                <span class="text-[10px] text-slate-500">${timeStr}</span>
            </div>
        `;
        
        container.appendChild(div);
    });
}

// ========== BIN GENERATION ==========

function updateDate() {
    const now = new Date();
    const options = { weekday: 'long', day: 'numeric', month: 'short', year: 'numeric' };
    const dateEl = document.getElementById('admin-date');
    if (dateEl) {
        dateEl.textContent = now.toLocaleDateString('en-GB', options);
    }
}

function generateBins() {
    bins = [];
    const positions = [
        {x: 20, y: 25}, {x: 75, y: 20}, {x: 35, y: 40},
        {x: 60, y: 35}, {x: 15, y: 55}, {x: 80, y: 50},
        {x: 45, y: 55}, {x: 25, y: 70}, {x: 70, y: 65},
        {x: 55, y: 25}, {x: 40, y: 68}, {x: 85, y: 35}
    ];

    for (let i = 0; i < 12; i++) {
        const fill = Math.floor(Math.random() * 100);
        const predictedFill = Math.min(100, fill + Math.floor(Math.random() * 30));
        
        bins.push({
            id: i + 1,
            x: positions[i].x,
            y: positions[i].y,
            fill: fill,
            predictedFill: predictedFill,
            type: i % 2 === 0 ? 'COMMERCIAL' : 'RESIDENTIAL',
            status: 'ACTIVE',
            address: ADDRESSES[i % ADDRESSES.length],
            lastCollected: new Date(Date.now() - Math.random() * 86400000 * 3)
        });
    }
}

// ========== RENDERING ==========

function renderAllMaps() {
    renderMap('admin-map-container', 'route-layer-admin');
    renderMap('driver-map-bg', 'route-layer-driver');
}

function renderMap(containerId, svgId) {
    const container = document.getElementById(containerId);
    if (!container) return;

    // Clear existing nodes (not SVG)
    container.querySelectorAll('.bin-node, .depot-node').forEach(el => el.remove());

    bins.forEach((bin, index) => {
        const el = document.createElement('div');
        const colorClass = bin.fill >= PRIORITY_THRESHOLD ? 'bg-red-500' : 
                           bin.fill >= WARNING_THRESHOLD ? 'bg-yellow-500' : 'bg-emerald-500';
        const animClass = bin.fill >= PRIORITY_THRESHOLD ? 'animate-priority' : 
                          bin.fill >= WARNING_THRESHOLD ? 'animate-warning' : 'animate-healthy';

        el.className = `bin-node w-8 h-8 rounded-full ${colorClass} ${animClass}`;
        el.style.left = `${bin.x}%`;
        el.style.top = `${bin.y}%`;
        el.style.transform = 'translate(-50%, -50%)';
        el.setAttribute('data-bin-id', bin.id);

        // Fill indicator
        const indicator = document.createElement('div');
        indicator.className = 'fill-indicator';
        indicator.textContent = `${bin.fill}%`;
        el.appendChild(indicator);

        // Prediction badge
        if (predictiveMode && bin.predictedFill >= PRIORITY_THRESHOLD && bin.fill < PRIORITY_THRESHOLD) {
            const badge = document.createElement('div');
            badge.className = 'prediction-badge';
            badge.textContent = 'AI';
            badge.title = `Predicted: ${bin.predictedFill}%`;
            el.appendChild(badge);
        }

        el.onclick = () => showBinDetails(bin);
        container.appendChild(el);
    });

    // Add depot
    const depot = document.createElement('div');
    depot.className = 'depot-node w-12 h-12';
    depot.style.left = `${DEPOT.x}%`;
    depot.style.top = `${DEPOT.y}%`;
    depot.innerHTML = '<i class="fa-solid fa-warehouse text-base"></i>';
    container.appendChild(depot);
}

function showBinDetails(bin) {
    const status = bin.fill >= PRIORITY_THRESHOLD ? '🔴 PRIORITY' : 
                  bin.fill >= WARNING_THRESHOLD ? '🟡 WARNING' : '🟢 OK';
    addAgentLog(`Bin #${bin.id}: ${bin.fill}% full | ${status}`, 'info');
    if (predictiveMode) {
        addAgentLog(`📊 Predicted: ${bin.predictedFill}% in 24hrs`, 'predict');
    }
}

// ========== ROUTE OPTIMIZATION ==========

function generateOptimizedRoute() {
    const btn = document.getElementById('generate-route-btn');
    btn.innerHTML = '<i class="fa-solid fa-spinner animate-spin"></i> Analyzing...';
    btn.disabled = true;

    addAgentLog('🔄 Starting route optimization...', 'info');

    setTimeout(() => {
        // AI selects bins to collect (priority + predicted priority)
        let binsToCollect = bins.filter(b => {
            if (b.fill >= PRIORITY_THRESHOLD) return true;
            if (predictiveMode && b.predictedFill >= PRIORITY_THRESHOLD) return true;
            return false;
        });

        // If none qualify, take top 5 by fill level
        if (binsToCollect.length === 0) {
            binsToCollect = [...bins].sort((a, b) => b.fill - a.fill).slice(0, 5);
            addAgentLog('ℹ️ No priority bins. Selecting top 5 by fill level.', 'info');
        }

        addAgentLog(`📍 Identified ${binsToCollect.length} bins for collection`, 'success');

        // Nearest neighbor algorithm for route optimization
        activeRoute = optimizeRoute(binsToCollect);
        
        // Calculate metrics
        const distance = calculateRouteDistance(activeRoute);
        const fuelUsed = (distance * 0.15).toFixed(1);
        const normalFuel = (distance * 0.25).toFixed(1);
        fuelSaved = (normalFuel - fuelUsed).toFixed(1);

        addAgentLog(`🛣️ Optimized route: ${distance.toFixed(1)} km`, 'success');
        addAgentLog(`⛽ Fuel estimate: ${fuelUsed}L (saved ${fuelSaved}L)`, 'success');

        // Draw route on maps
        drawRoute('route-layer-admin', activeRoute);
        drawRoute('route-layer-driver', activeRoute);

        // Update UI
        updateStats();
        updateRoutePanel(activeRoute.length, distance, fuelUsed);
        
        // Update driver screen
        totalRouteDistance = distance;
        updateDriverPreshift();

        btn.innerHTML = '<i class="fa-solid fa-check"></i> Route Generated';
        btn.classList.remove('btn-primary');
        btn.classList.add('bg-emerald-600');
        routeGenerated = true;

        setTimeout(() => {
            btn.innerHTML = '<i class="fa-solid fa-route"></i> Regenerate Route';
            btn.classList.add('btn-primary');
            btn.classList.remove('bg-emerald-600');
            btn.disabled = false;
        }, 2000);

    }, 1500);
}

function optimizeRoute(binsToCollect) {
    // Sort by priority first (highest fill level bins first)
    // Then apply nearest neighbor for efficiency within priority groups
    
    // Separate into priority tiers
    const priorityBins = binsToCollect.filter(b => b.fill >= PRIORITY_THRESHOLD);
    const normalBins = binsToCollect.filter(b => b.fill < PRIORITY_THRESHOLD);
    
    // Sort priority bins by fill level (highest first)
    priorityBins.sort((a, b) => b.fill - a.fill);
    
    // Apply nearest neighbor within each group
    const route = [];
    let current = DEPOT;
    
    // First, handle all priority bins
    const remainingPriority = [...priorityBins];
    while (remainingPriority.length > 0) {
        let nearest = null;
        let nearestDist = Infinity;
        
        remainingPriority.forEach(bin => {
            const dist = Math.sqrt(Math.pow(bin.x - current.x, 2) + Math.pow(bin.y - current.y, 2));
            if (dist < nearestDist) {
                nearestDist = dist;
                nearest = bin;
            }
        });
        
        if (nearest) {
            nearest.isPriority = true; // Mark as priority for UI
            route.push(nearest);
            remainingPriority.splice(remainingPriority.indexOf(nearest), 1);
            current = nearest;
        }
    }
    
    // Then handle normal bins
    const remainingNormal = [...normalBins];
    while (remainingNormal.length > 0) {
        let nearest = null;
        let nearestDist = Infinity;
        
        remainingNormal.forEach(bin => {
            const dist = Math.sqrt(Math.pow(bin.x - current.x, 2) + Math.pow(bin.y - current.y, 2));
            if (dist < nearestDist) {
                nearestDist = dist;
                nearest = bin;
            }
        });
        
        if (nearest) {
            nearest.isPriority = false;
            route.push(nearest);
            remainingNormal.splice(remainingNormal.indexOf(nearest), 1);
            current = nearest;
        }
    }
    
    addAgentLog(`🔴 ${priorityBins.length} priority bins queued first`, 'alert');
    
    return route;
}

function calculateRouteDistance(route) {
    if (route.length === 0) return 0;
    
    let distance = 0;
    let prev = DEPOT;
    
    route.forEach(bin => {
        distance += Math.sqrt(Math.pow(bin.x - prev.x, 2) + Math.pow(bin.y - prev.y, 2));
        prev = bin;
    });
    
    // Return to depot
    distance += Math.sqrt(Math.pow(DEPOT.x - prev.x, 2) + Math.pow(DEPOT.y - prev.y, 2));
    
    return distance * 0.1; // Scale to km
}

function drawRoute(svgId, route) {
    const svg = document.getElementById(svgId);
    if (!svg) return;
    svg.innerHTML = '';

    if (route.length === 0) return;

    // Create path points
    let pathD = `M ${DEPOT.x}% ${DEPOT.y}%`;
    route.forEach(bin => {
        pathD += ` L ${bin.x}% ${bin.y}%`;
    });
    pathD += ` L ${DEPOT.x}% ${DEPOT.y}%`; // Return to depot

    // Draw path
    const path = document.createElementNS('http://www.w3.org/2000/svg', 'path');
    path.setAttribute('d', pathD);
    path.setAttribute('fill', 'none');
    path.setAttribute('stroke', '#3b82f6');
    path.setAttribute('stroke-width', '3');
    path.setAttribute('stroke-linecap', 'round');
    path.setAttribute('stroke-linejoin', 'round');
    path.classList.add('route-path');
    svg.appendChild(path);

    // Add route numbers
    route.forEach((bin, idx) => {
        const circle = document.createElementNS('http://www.w3.org/2000/svg', 'circle');
        circle.setAttribute('cx', `${bin.x}%`);
        circle.setAttribute('cy', `${bin.y}%`);
        circle.setAttribute('r', '12');
        circle.setAttribute('fill', '#1e40af');
        circle.setAttribute('stroke', 'white');
        circle.setAttribute('stroke-width', '2');
        svg.appendChild(circle);

        const text = document.createElementNS('http://www.w3.org/2000/svg', 'text');
        text.setAttribute('x', `${bin.x}%`);
        text.setAttribute('y', `${bin.y}%`);
        text.setAttribute('text-anchor', 'middle');
        text.setAttribute('dominant-baseline', 'central');
        text.setAttribute('fill', 'white');
        text.setAttribute('font-size', '10');
        text.setAttribute('font-weight', 'bold');
        text.textContent = idx + 1;
        svg.appendChild(text);
    });
}

function updateRoutePanel(stops, distance, fuel) {
    const stopsEl = document.getElementById('route-stops');
    const distanceEl = document.getElementById('route-distance');
    const fuelEl = document.getElementById('route-fuel');
    const panelEl = document.getElementById('route-info-panel');
    
    if (stopsEl) stopsEl.textContent = `${stops} Stops`;
    if (distanceEl) distanceEl.textContent = `${distance.toFixed(1)} km`;
    if (fuelEl) fuelEl.textContent = `${fuel} L`;
    if (panelEl) panelEl.classList.remove('hidden-view');
}

// ========== AI FEATURES ==========

function runPredictiveAnalysis() {
    addAgentLog('🔮 Running predictive analysis...', 'info');
    
    setTimeout(() => {
        let predictions = 0;
        bins.forEach(bin => {
            if (bin.fill < PRIORITY_THRESHOLD && bin.predictedFill >= PRIORITY_THRESHOLD) {
                predictions++;
                addAgentLog(`⚠️ Bin #${bin.id} predicted to reach ${bin.predictedFill}% in 24hrs`, 'predict');
            }
        });
        
        if (predictions === 0) {
            addAgentLog('✅ No bins predicted to overflow in next 24hrs', 'success');
        } else {
            addAgentLog(`📈 ${predictions} bins flagged for proactive collection`, 'predict');
        }
        
        const predictedStatEl = document.getElementById('predicted-stat');
        if (predictedStatEl) predictedStatEl.textContent = predictions;
        renderAllMaps();
    }, 1000);
}

function togglePredictive() {
    predictiveMode = document.getElementById('predict-toggle').checked;
    addAgentLog(predictiveMode ? '🧠 Predictive mode enabled' : '🧠 Predictive mode disabled', 'info');
    
    // Record override if shift is active
    if (driverShiftActive) {
        operationalOverrides.push({
            type: 'predictive',
            action: predictiveMode ? 'Predictive Analytics Enabled' : 'Predictive Analytics Disabled',
            timestamp: new Date().toISOString()
        });
    }
    
    renderAllMaps();
    updateStats();
}

// ========== SIMULATION ==========

function toggleSimulation() {
    if (simulationInterval) {
        clearInterval(simulationInterval);
        simulationInterval = null;
        addAgentLog('📡 Sensor stream paused', 'info');
        
        // Record override if shift is active
        if (driverShiftActive) {
            operationalOverrides.push({
                type: 'telemetry',
                action: 'Live Telemetry Disabled',
                timestamp: new Date().toISOString()
            });
        }
    } else {
        addAgentLog('📡 Live sensor stream activated', 'success');
        
        // Record override if shift is active
        if (driverShiftActive) {
            operationalOverrides.push({
                type: 'telemetry',
                action: 'Live Telemetry Enabled',
                timestamp: new Date().toISOString()
            });
        }
        
        simulationInterval = setInterval(() => {
            // Randomly increase fill levels
            const randomBin = bins[Math.floor(Math.random() * bins.length)];
            const increase = Math.floor(Math.random() * 8) + 1;
            randomBin.fill = Math.min(100, randomBin.fill + increase);
            randomBin.predictedFill = Math.min(100, randomBin.fill + Math.floor(Math.random() * 20) + 10);
            
            addAgentLog(`📥 Bin #${randomBin.id}: ${randomBin.fill}% (+${increase}%)`, 'info');
            
            if (randomBin.fill >= PRIORITY_THRESHOLD) {
                addAgentLog(`🚨 ALERT: Bin #${randomBin.id} requires immediate collection!`, 'alert');
            }
            
            renderAllMaps();
            updateStats();
        }, 3000);
    }
}

function simulateFillIncrease() {
    addAgentLog('⏫ Simulating high-traffic period...', 'info');
    bins.forEach(bin => {
        bin.fill = Math.min(100, bin.fill + Math.floor(Math.random() * 30) + 10);
        bin.predictedFill = Math.min(100, bin.fill + Math.floor(Math.random() * 20));
    });
    renderAllMaps();
    updateStats();
    addAgentLog('✅ Fill levels updated', 'success');
}

function resetBins() {
    generateBins();
    activeRoute = [];
    routeGenerated = false;
    
    // Clear routes
    const adminRoute = document.getElementById('route-layer-admin');
    const driverRoute = document.getElementById('route-layer-driver');
    const routePanel = document.getElementById('route-info-panel');
    
    if (adminRoute) adminRoute.innerHTML = '';
    if (driverRoute) driverRoute.innerHTML = '';
    if (routePanel) routePanel.classList.add('hidden-view');
    
    renderAllMaps();
    updateStats();
    addAgentLog('🔄 All bins reset to random states', 'info');
    
    const btn = document.getElementById('generate-route-btn');
    if (btn) {
        btn.innerHTML = '<i class="fa-solid fa-route"></i> Generate Optimized Route';
        btn.disabled = false;
    }
}

function toggleWeekend() {
    isWeekend = document.getElementById('weekend-toggle').checked;
    addAgentLog(isWeekend ? '📅 Weekend pattern applied (+20% commercial)' : '📅 Weekday pattern restored', 'info');
    
    // Record override if shift is active
    if (driverShiftActive) {
        operationalOverrides.push({
            type: 'seasonal',
            action: isWeekend ? 'Seasonal Logic Enabled (Weekend Mode)' : 'Seasonal Logic Disabled',
            timestamp: new Date().toISOString()
        });
    }
    
    if (isWeekend) {
        bins.filter(b => b.type === 'COMMERCIAL').forEach(bin => {
            bin.fill = Math.min(100, bin.fill + 15);
            bin.predictedFill = Math.min(100, bin.predictedFill + 20);
        });
        renderAllMaps();
        updateStats();
    }
}

// ========== UI UPDATES ==========

function updateStats() {
    const priorityBins = bins.filter(b => b.fill >= PRIORITY_THRESHOLD).length;
    const predictedBins = predictiveMode ? 
        bins.filter(b => b.fill < PRIORITY_THRESHOLD && b.predictedFill >= PRIORITY_THRESHOLD).length : 0;
    const efficiency = Math.max(0, 100 - (priorityBins * 5) - (predictedBins * 2));

    const priorityStat = document.getElementById('priority-stat');
    const predictedStat = document.getElementById('predicted-stat');
    const effStat = document.getElementById('eff-stat');
    const fuelStat = document.getElementById('fuel-stat');
    
    if (priorityStat) priorityStat.textContent = priorityBins;
    if (predictedStat) predictedStat.textContent = predictedBins;
    if (effStat) effStat.textContent = `${Math.round(efficiency)}%`;
    if (fuelStat) fuelStat.textContent = `${fuelSaved} L`;
}

function addAgentLog(message, type = 'info') {
    const logs = document.getElementById('agent-logs');
    if (!logs) return;
    
    const entry = document.createElement('div');
    entry.className = 'flex items-start gap-3 text-xs animate-fade-in-up';
    
    const colors = {
        'info': 'text-slate-300',
        'success': 'text-emerald-400',
        'alert': 'text-red-400',
        'predict': 'text-amber-400'
    };
    
    entry.innerHTML = `
        <span class="${colors[type] || colors.info}">${message}</span>
        <span class="text-slate-500 ml-auto text-[10px] whitespace-nowrap">${new Date().toLocaleTimeString()}</span>
    `;
    
    // Remove initial message
    const initial = logs.querySelector('.italic');
    if (initial) initial.remove();
    
    logs.appendChild(entry);
    logs.scrollTop = logs.scrollHeight;
    
    // Limit logs
    while (logs.children.length > 20) {
        logs.removeChild(logs.firstChild);
    }
}

// ========== NAVIGATION ==========

function enterApp(role) {
    document.getElementById('screen-login').classList.add('hidden-view');
    document.getElementById(`screen-${role}`).classList.remove('hidden-view');
    
    if (role === 'driver') {
        // Reset driver state
        driverCurrentIndex = 0;
        collectedBins = [];
        driverShiftActive = false;
        
        // Reset UI to preshift state
        document.getElementById('driver-preshift').classList.remove('hidden');
        document.getElementById('driver-active').style.display = 'none';
        document.getElementById('driver-completed').style.display = 'none';
        
        if (routeGenerated && activeRoute.length > 0) {
            updateDriverPreshift();
            // Draw initial route on driver map
            drawRoute('route-layer-driver', activeRoute);
        }
    }
}

function switchAdminTab(tab) {
    ['home', 'map', 'controls', 'history'].forEach(t => {
        const tabEl = document.getElementById(`tab-admin-${t}`);
        const navEl = document.getElementById(`nav-${t}`);
        if (tabEl) tabEl.classList.add('hidden-view');
        if (navEl) navEl.classList.remove('active');
    });
    
    const activeTab = document.getElementById(`tab-admin-${tab}`);
    const activeNav = document.getElementById(`nav-${tab}`);
    if (activeTab) activeTab.classList.remove('hidden-view');
    if (activeNav) activeNav.classList.add('active');
    
    // Refresh history list when switching to history tab
    if (tab === 'history') {
        renderTripHistory();
    }
}

// ========== DRIVER FUNCTIONS ==========

function updateDriverPreshift() {
    const priorityCount = activeRoute.filter(b => b.fill >= PRIORITY_THRESHOLD).length;
    const estTime = Math.round(activeRoute.length * 4 + totalRouteDistance * 2);
    
    const preshiftStops = document.getElementById('preshift-stops');
    const preshiftDistance = document.getElementById('preshift-distance');
    const preshiftTime = document.getElementById('preshift-time');
    
    if (preshiftStops) preshiftStops.textContent = activeRoute.length;
    if (preshiftDistance) preshiftDistance.textContent = totalRouteDistance.toFixed(1);
    if (preshiftTime) preshiftTime.textContent = estTime;
    
    // Show priority warning if needed
    const warningEl = document.getElementById('priority-warning');
    if (warningEl) {
        if (priorityCount > 0) {
            const priorityCountEl = document.getElementById('priority-count');
            if (priorityCountEl) priorityCountEl.textContent = priorityCount;
            warningEl.style.display = 'flex';
        } else {
            warningEl.style.display = 'none';
        }
    }
}

function startShift() {
    if (!routeGenerated || activeRoute.length === 0) {
        alert('No route available. Please wait for admin to generate a route.');
        return;
    }
    
    driverShiftActive = true;
    driverCurrentIndex = 0;
    collectedBins = [];
    collectionTimestamps = [];
    operationalOverrides = [];
    shiftStartTime = new Date();
    
    // Assign random driver for demo
    currentDriver = DRIVERS[Math.floor(Math.random() * DRIVERS.length)];
    
    // Hide preshift, show active navigation
    document.getElementById('driver-preshift').classList.add('hidden');
    document.getElementById('driver-active').classList.remove('hidden');
    document.getElementById('driver-active').style.display = 'block';
    
    // Render driver-specific map
    renderDriverMap();
    updateCurrentStopUI();
}

function renderDriverMap() {
    const container = document.getElementById('driver-map-bg');
    if (!container) return;
    
    // Clear existing bins
    container.querySelectorAll('.bin-node, .depot-node').forEach(el => el.remove());
    
    // Render all route bins with appropriate styling
    activeRoute.forEach((bin, idx) => {
        const el = document.createElement('div');
        const isCollected = collectedBins.includes(bin.id);
        const isCurrent = idx === driverCurrentIndex && !isCollected;
        const isPriority = bin.fill >= PRIORITY_THRESHOLD;
        
        let classes = 'bin-node w-10 h-10 rounded-full';
        
        if (isCollected) {
            classes += ' bg-slate-400 bin-collected';
        } else if (isCurrent) {
            classes += isPriority ? ' bg-red-500 current-target-marker' : ' bg-blue-500 current-target-marker';
        } else if (isPriority) {
            classes += ' bg-red-500 driver-bin-priority';
        } else {
            classes += ' bg-emerald-500';
        }
        
        el.className = classes;
        el.style.left = `${bin.x}%`;
        el.style.top = `${bin.y}%`;
        el.style.transform = 'translate(-50%, -50%)';
        el.style.zIndex = isCurrent ? '25' : '20';
        
        // Show order number for non-collected bins
        if (!isCollected) {
            const numBadge = document.createElement('div');
            numBadge.className = 'absolute -top-2 -right-2 w-5 h-5 bg-slate-900 rounded-full flex items-center justify-center text-white text-[10px] font-bold border-2 border-white';
            numBadge.textContent = idx + 1;
            el.appendChild(numBadge);
        } else {
            const checkMark = document.createElement('i');
            checkMark.className = 'fa-solid fa-check text-white text-sm';
            el.appendChild(checkMark);
        }
        
        container.appendChild(el);
    });
    
    // Add depot
    const depot = document.createElement('div');
    depot.className = 'depot-node w-12 h-12';
    depot.style.left = `${DEPOT.x}%`;
    depot.style.top = `${DEPOT.y}%`;
    depot.innerHTML = '<i class="fa-solid fa-warehouse text-base"></i>';
    container.appendChild(depot);
    
    // Draw route line to current and remaining stops
    drawDriverRoute();
}

function drawDriverRoute() {
    const svg = document.getElementById('route-layer-driver');
    if (!svg) return;
    svg.innerHTML = '';
    
    // Get remaining route (from current position)
    const remainingRoute = activeRoute.slice(driverCurrentIndex).filter(b => !collectedBins.includes(b.id));
    if (remainingRoute.length === 0) return;
    
    // Starting point: depot or last collected bin position
    let startPoint = DEPOT;
    if (driverCurrentIndex > 0 && collectedBins.length > 0) {
        const lastCollected = activeRoute.find(b => b.id === collectedBins[collectedBins.length - 1]);
        if (lastCollected) startPoint = lastCollected;
    }
    
    // Create bold directional path
    let pathD = `M ${startPoint.x}% ${startPoint.y}%`;
    remainingRoute.forEach(bin => {
        pathD += ` L ${bin.x}% ${bin.y}%`;
    });
    pathD += ` L ${DEPOT.x}% ${DEPOT.y}%`; // Return to depot
    
    // Draw shadow/glow for visibility
    const shadowPath = document.createElementNS('http://www.w3.org/2000/svg', 'path');
    shadowPath.setAttribute('d', pathD);
    shadowPath.setAttribute('fill', 'none');
    shadowPath.setAttribute('stroke', 'rgba(59, 130, 246, 0.3)');
    shadowPath.setAttribute('stroke-width', '12');
    shadowPath.setAttribute('stroke-linecap', 'round');
    shadowPath.setAttribute('stroke-linejoin', 'round');
    svg.appendChild(shadowPath);
    
    // Draw main path - bold and clear
    const mainPath = document.createElementNS('http://www.w3.org/2000/svg', 'path');
    mainPath.setAttribute('d', pathD);
    mainPath.setAttribute('fill', 'none');
    mainPath.setAttribute('stroke', '#3b82f6');
    mainPath.setAttribute('stroke-width', '5');
    mainPath.setAttribute('stroke-linecap', 'round');
    mainPath.setAttribute('stroke-linejoin', 'round');
    mainPath.classList.add('driver-route-path');
    svg.appendChild(mainPath);
    
    // Add direction arrows along the path
    if (remainingRoute.length > 0) {
        const firstBin = remainingRoute[0];
        const midX = (startPoint.x + firstBin.x) / 2;
        const midY = (startPoint.y + firstBin.y) / 2;
        
        // Calculate arrow rotation
        const angle = Math.atan2(firstBin.y - startPoint.y, firstBin.x - startPoint.x) * 180 / Math.PI;
        
        const arrow = document.createElementNS('http://www.w3.org/2000/svg', 'polygon');
        arrow.setAttribute('points', '-8,-6 8,0 -8,6');
        arrow.setAttribute('fill', '#3b82f6');
        arrow.setAttribute('transform', `translate(${midX}%, ${midY}%) rotate(${angle})`);
        arrow.classList.add('driver-route-arrow');
        svg.appendChild(arrow);
    }
}

function updateCurrentStopUI() {
    if (driverCurrentIndex >= activeRoute.length) {
        completeShift();
        return;
    }
    
    const currentBin = activeRoute[driverCurrentIndex];
    const isPriority = currentBin.fill >= PRIORITY_THRESHOLD;
    const remainingCount = activeRoute.length - driverCurrentIndex - collectedBins.length;
    const remainingDist = calculateRemainingDistance();
    const eta = Math.round(2 + remainingDist * 0.5); // 2 min base + 0.5 min/km
    
    // Update current stop card
    const currentStopNum = document.getElementById('current-stop-num');
    const currentBinLabel = document.getElementById('current-bin-label');
    const currentAddress = document.getElementById('current-address');
    const currentFill = document.getElementById('current-fill');
    const currentEta = document.getElementById('current-eta');
    const remainingStops = document.getElementById('remaining-stops');
    const remainingDistance = document.getElementById('remaining-distance');
    
    if (currentStopNum) currentStopNum.textContent = driverCurrentIndex + 1;
    if (currentBinLabel) currentBinLabel.textContent = `Bin #${currentBin.id}`;
    if (currentAddress) currentAddress.textContent = currentBin.address;
    if (currentFill) currentFill.textContent = `${currentBin.fill}%`;
    if (currentEta) currentEta.textContent = `${eta} min`;
    if (remainingStops) remainingStops.textContent = remainingCount;
    if (remainingDistance) remainingDistance.textContent = remainingDist.toFixed(1);
    
    // Fill bar
    const fillBar = document.getElementById('fill-bar');
    if (fillBar) {
        fillBar.style.width = `${currentBin.fill}%`;
        if (currentBin.fill >= PRIORITY_THRESHOLD) {
            fillBar.className = 'h-full bg-gradient-to-r from-red-500 to-red-400 rounded-full transition-all duration-300';
        } else if (currentBin.fill >= WARNING_THRESHOLD) {
            fillBar.className = 'h-full bg-gradient-to-r from-yellow-500 to-yellow-400 rounded-full transition-all duration-300';
        } else {
            fillBar.className = 'h-full bg-gradient-to-r from-emerald-500 to-emerald-400 rounded-full transition-all duration-300';
        }
    }
    
    // Priority badge & card styling
    const priorityBadge = document.getElementById('priority-badge');
    const stopCard = document.getElementById('current-stop-card');
    const stopNumBadge = document.getElementById('stop-number-badge');
    
    if (isPriority) {
        if (priorityBadge) priorityBadge.classList.remove('hidden');
        if (stopCard) stopCard.classList.add('priority');
        if (stopNumBadge) stopNumBadge.className = 'w-12 h-12 rounded-2xl bg-red-600 flex items-center justify-center';
    } else {
        if (priorityBadge) priorityBadge.classList.add('hidden');
        if (stopCard) stopCard.classList.remove('priority');
        if (stopNumBadge) stopNumBadge.className = 'w-12 h-12 rounded-2xl bg-blue-600 flex items-center justify-center';
    }
    
    // Update progress ring
    updateProgressRing();
}

function calculateRemainingDistance() {
    const remaining = activeRoute.slice(driverCurrentIndex).filter(b => !collectedBins.includes(b.id));
    if (remaining.length === 0) return 0;
    
    let distance = 0;
    let prev = driverCurrentIndex > 0 ? activeRoute[driverCurrentIndex - 1] : DEPOT;
    
    remaining.forEach(bin => {
        distance += Math.sqrt(Math.pow(bin.x - prev.x, 2) + Math.pow(bin.y - prev.y, 2));
        prev = bin;
    });
    
    distance += Math.sqrt(Math.pow(DEPOT.x - prev.x, 2) + Math.pow(DEPOT.y - prev.y, 2));
    
    return distance * 0.1;
}

function updateProgressRing() {
    const total = activeRoute.length;
    const completed = collectedBins.length;
    const percent = Math.round((completed / total) * 100);
    
    const progressPercent = document.getElementById('progress-percent');
    const circle = document.getElementById('progress-circle');
    
    if (progressPercent) progressPercent.textContent = `${percent}%`;
    
    if (circle) {
        const circumference = 150.8; // 2 * PI * 24
        const offset = circumference - (percent / 100) * circumference;
        circle.style.strokeDashoffset = offset;
    }
}

function markAsCollected() {
    if (driverCurrentIndex >= activeRoute.length) return;
    
    const currentBin = activeRoute[driverCurrentIndex];
    collectedBins.push(currentBin.id);
    
    // Record collection timestamp
    collectionTimestamps.push({
        binId: currentBin.id,
        timestamp: new Date().toISOString(),
        address: currentBin.address,
        fillLevel: currentBin.fill,
        isPriority: currentBin.fill >= PRIORITY_THRESHOLD
    });
    
    // Visual feedback
    const btn = document.getElementById('btn-mark-collected');
    if (btn) {
        btn.innerHTML = '<i class="fa-solid fa-check text-2xl"></i> Collected!';
        btn.classList.add('celebrate');
        
        setTimeout(() => {
            btn.innerHTML = '<i class="fa-solid fa-check text-2xl"></i> Mark as Collected';
            btn.classList.remove('celebrate');
            
            // Move to next stop
            driverCurrentIndex++;
            
            // Re-render map and update UI
            renderDriverMap();
            updateCurrentStopUI();
        }, 500);
    }
}

function skipCurrentBin() {
    if (driverCurrentIndex >= activeRoute.length) return;
    
    // Move bin to end of route
    const skippedBin = activeRoute.splice(driverCurrentIndex, 1)[0];
    activeRoute.push(skippedBin);
    
    // Re-render
    renderDriverMap();
    updateCurrentStopUI();
}

function completeShift() {
    const shiftEndTime = new Date();
    const durationMs = shiftEndTime - shiftStartTime;
    const durationMin = Math.round(durationMs / 60000) || Math.round(activeRoute.length * 4 + totalRouteDistance * 2);
    
    // Calculate efficiency
    const efficiency = Math.round((collectedBins.length / activeRoute.length) * 100);
    
    // Create trip record
    const tripRecord = {
        id: `TRIP-${Date.now()}`,
        timestamp: shiftStartTime.toISOString(),
        driverId: currentDriver?.id || 'DRV-001',
        driverName: currentDriver?.name || 'Unknown Driver',
        vehicleId: currentDriver?.vehicle || 'ECO-T01',
        binsCollected: collectedBins.length,
        totalBins: activeRoute.length,
        distance: parseFloat(totalRouteDistance.toFixed(1)),
        duration: durationMin,
        fuelSaved: parseFloat(fuelSaved) || parseFloat((totalRouteDistance * 0.1).toFixed(1)),
        efficiency: efficiency,
        route: activeRoute.map(b => ({ x: b.x, y: b.y, id: b.id, isPriority: b.fill >= PRIORITY_THRESHOLD })),
        depot: { x: DEPOT.x, y: DEPOT.y },
        collections: collectionTimestamps,
        overrides: [...operationalOverrides]
    };
    
    // Add to history and save
    tripHistory.push(tripRecord);
    saveTripHistory();
    
    // Show completion UI
    document.getElementById('driver-active').style.display = 'none';
    document.getElementById('driver-completed').classList.remove('hidden');
    document.getElementById('driver-completed').style.display = 'flex';
    
    const completedBins = document.getElementById('completed-bins');
    const completedDistance = document.getElementById('completed-distance');
    
    if (completedBins) completedBins.textContent = collectedBins.length;
    if (completedDistance) completedDistance.textContent = `${totalRouteDistance.toFixed(1)} km`;
}

function endShift() {
    driverShiftActive = false;
    driverCurrentIndex = 0;
    collectedBins = [];
    
    document.getElementById('driver-completed').style.display = 'none';
    document.getElementById('driver-preshift').classList.remove('hidden');
    document.getElementById('driver-active').style.display = 'none';
    
    logout();
}

function startDriverRoute() {
    // Legacy function - now handled by startShift()
    startShift();
}

function logout() { 
    location.reload(); 
}

function goBackToLogin() {
    // Hide all screens
    document.getElementById('screen-admin').classList.add('hidden-view');
    document.getElementById('screen-driver').classList.add('hidden-view');
    
    // Reset driver state
    driverShiftActive = false;
    driverCurrentIndex = 0;
    collectedBins = [];
    
    // Reset driver UI panels
    document.getElementById('driver-preshift').classList.remove('hidden');
    document.getElementById('driver-active').style.display = 'none';
    document.getElementById('driver-completed').style.display = 'none';
    
    // Show login screen
    document.getElementById('screen-login').classList.remove('hidden-view');
}

// ========== INIT ==========
window.onload = init;
