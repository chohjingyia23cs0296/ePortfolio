import 'package:flutter/material.dart';

void main() {
  runApp(const DailyActivityApp());
}

// Data Model
class Activity {
  String name;
  String info;

  Activity({required this.name, required this.info});
}

class DailyActivityApp extends StatelessWidget {
  const DailyActivityApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Daily Activities Recorder',
      // Primary theme color matching the mockup
      theme: ThemeData(
        primaryColor: const Color(0xFF0D6EFD), 
        scaffoldBackgroundColor: Colors.grey[100], // Light background to make the white container pop
      ),
      home: const ActivityPage(),
    );
  }
}

class ActivityPage extends StatefulWidget {
  const ActivityPage({super.key});

  @override
  State<ActivityPage> createState() => _ActivityPageState();
}

class _ActivityPageState extends State<ActivityPage> {
  final TextEditingController _nameController = TextEditingController();
  final TextEditingController _infoController = TextEditingController();

  final List<Activity> _activities = [];
  
  bool _isEditing = false; 
  int _editingIndex = -1;

  void _addOrUpdateActivity() {
    final String name = _nameController.text.trim();
    final String info = _infoController.text.trim();

    if (name.isEmpty || info.isEmpty) return;

    if (_isEditing) {
      _updateActivity(name, info);
    } else {
      _addActivity(name, info);
    }
  }

  void _addActivity(String name, String info) {
    setState(() {
      _activities.add(Activity(name: name, info: info));
    });
    _clearFields();
  }

  void _editActivity(int index) {
    setState(() {
      _nameController.text = _activities[index].name;
      _infoController.text = _activities[index].info;
      _isEditing = true; 
      _editingIndex = index; 
    });
  }

  void _updateActivity(String name, String info) {
    setState(() {
      _activities[_editingIndex].name = name; 
      _activities[_editingIndex].info = info;
      _isEditing = false; 
      _editingIndex = -1;
    });
    _clearFields();
  }

  void _cancelEdit() {
    setState(() {
      _isEditing = false; 
      _editingIndex = -1;
    });
    _clearFields(); 
  }

  void _deleteActivity(int index) {
    setState(() {
      _activities.removeAt(index);
      if (_isEditing && _editingIndex == index) {
        _cancelEdit(); 
      } else if (_isEditing && _editingIndex > index) {
        _editingIndex--; 
      }
    });
  }

  void _showDeleteDialog(int index) {
    showDialog(
      context: context,
      builder: (BuildContext context) {
        return AlertDialog(
          title: const Text('Confirm Delete'),
          content: const Text('Are you sure you want to delete this activity?'),
          actions: [
            TextButton(
              onPressed: () => Navigator.of(context).pop(),
              child: const Text('Cancel'),
            ),
            TextButton(
              onPressed: () {
                Navigator.of(context).pop(); 
                _deleteActivity(index);      
              },
              child: const Text('Delete', style: TextStyle(color: Colors.red)),
            ),
          ],
        );
      },
    );
  }

  void _clearFields() {
    _nameController.clear();
    _infoController.clear();
  }

  @override
  Widget build(BuildContext context) {
    // Defines the consistent blue color from the mockup
    const Color primaryBlue = Color(0xFF0D6EFD);

    return Scaffold(
      appBar: AppBar(
        backgroundColor: primaryBlue,
        elevation: 0,
        title: Row(
          children: const [
            Icon(Icons.assignment, color: Colors.white, size: 24),
            SizedBox(width: 10),
            Text(
              'Daily Activities Recorder',
              style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold, fontSize: 20),
            ),
          ],
        ),
      ),
      body: Center(
        child: Container(
          // This container mimics the large white card in the mockup
          margin: const EdgeInsets.all(16.0),
          decoration: BoxDecoration(
            color: Colors.white,
            borderRadius: BorderRadius.circular(12),
            boxShadow: const [
              BoxShadow(color: Colors.black12, blurRadius: 10, offset: Offset(0, 4)),
            ],
          ),
          child: Column(
            children: [
              // --- FORM SECTION ---
              Padding(
                padding: const EdgeInsets.all(20.0),
                child: Column(
                  children: [
                    TextField(
                      controller: _nameController,
                      decoration: InputDecoration(
                        hintText: 'Activity name...', // Changed from labelText to hintText to match mockup
                        hintStyle: TextStyle(color: Colors.grey.shade400),
                        contentPadding: const EdgeInsets.symmetric(horizontal: 16, vertical: 14),
                        enabledBorder: OutlineInputBorder(
                          borderRadius: BorderRadius.circular(8),
                          borderSide: BorderSide(color: Colors.grey.shade300),
                        ),
                        focusedBorder: OutlineInputBorder(
                          borderRadius: BorderRadius.circular(8),
                          borderSide: const BorderSide(color: primaryBlue),
                        ),
                      ),
                    ),
                    const SizedBox(height: 12),
                    TextField(
                      controller: _infoController,
                      decoration: InputDecoration(
                        hintText: 'Time / Category...',
                        hintStyle: TextStyle(color: Colors.grey.shade400),
                        contentPadding: const EdgeInsets.symmetric(horizontal: 16, vertical: 14),
                        enabledBorder: OutlineInputBorder(
                          borderRadius: BorderRadius.circular(8),
                          borderSide: BorderSide(color: Colors.grey.shade300),
                        ),
                        focusedBorder: OutlineInputBorder(
                          borderRadius: BorderRadius.circular(8),
                          borderSide: const BorderSide(color: primaryBlue),
                        ),
                      ),
                    ),
                    const SizedBox(height: 16),
                    Row(
                      children: [
                        Expanded(
                          flex: 1,
                          child: ElevatedButton(
                            style: ElevatedButton.styleFrom(
                              backgroundColor: primaryBlue,
                              foregroundColor: Colors.white,
                              padding: const EdgeInsets.symmetric(vertical: 14),
                              shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8)),
                              elevation: 0,
                            ),
                            onPressed: _addOrUpdateActivity,
                            child: Text(
                              _isEditing ? 'Update Activity' : '+ Add Activity',
                              style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                            ),
                          ),
                        ),
                        const SizedBox(width: 10),
                        Expanded(
                          flex: 1,
                          child: OutlinedButton(
                            style: OutlinedButton.styleFrom(
                              padding: const EdgeInsets.symmetric(vertical: 14),
                              side: const BorderSide(color: primaryBlue),
                              shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8)),
                            ),
                            onPressed: _isEditing ? _cancelEdit : _clearFields,
                            child: Text(
                              _isEditing ? 'Cancel' : 'Clear',
                              style: const TextStyle(fontSize: 16, color: primaryBlue, fontWeight: FontWeight.bold),
                            ),
                          ),
                        ),
                      ],
                    ),
                  ],
                ),
              ),
              
              // Light grey divider line
              Divider(height: 1, thickness: 1, color: Colors.grey.shade200),
              
              // --- ACTIVITIES LIST SECTION ---
              Expanded(
                child: Padding(
                  padding: const EdgeInsets.all(20.0),
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text(
                        'ACTIVITIES',
                        style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: 12,
                          letterSpacing: 1.2,
                          color: Colors.blueGrey.shade300,
                        ),
                      ),
                      const SizedBox(height: 12),
                      Expanded(
                        child: _activities.isEmpty
                            ? Center(child: Text('No activities added yet.', style: TextStyle(color: Colors.grey.shade500)))
                            : ListView.builder(
                                itemCount: _activities.length,
                                itemBuilder: (context, index) {
                                  return Container(
                                    margin: const EdgeInsets.only(bottom: 12),
                                    decoration: BoxDecoration(
                                      color: Colors.white,
                                      borderRadius: BorderRadius.circular(10),
                                      border: Border.all(color: Colors.grey.shade200),
                                    ),
                                    child: ListTile(
                                      contentPadding: const EdgeInsets.symmetric(horizontal: 16, vertical: 4),
                                      title: Text(
                                        _activities[index].name,
                                        style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 16),
                                      ),
                                      subtitle: Padding(
                                        padding: const EdgeInsets.only(top: 4.0),
                                        child: Text(
                                          _activities[index].info,
                                          style: TextStyle(color: Colors.grey.shade500, fontSize: 13),
                                        ),
                                      ),
                                      trailing: Row(
                                        mainAxisSize: MainAxisSize.min,
                                        children: [
                                          IconButton(
                                            icon: const Icon(Icons.edit, color: Colors.blueGrey, size: 22),
                                            onPressed: () => _editActivity(index),
                                            tooltip: 'Edit',
                                          ),
                                          IconButton(
                                            icon: const Icon(Icons.delete_outline, color: Colors.redAccent, size: 22),
                                            onPressed: () => _showDeleteDialog(index),
                                            tooltip: 'Delete',
                                          ),
                                        ],
                                      ),
                                    ),
                                  );
                                },
                              ),
                      ),
                    ],
                  ),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}