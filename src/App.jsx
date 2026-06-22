import React from 'react';
import Navbar from './components/Navbar';
import HeroSection from './components/HeroSection';
import AboutSection from './components/AboutSection';
import SkillsSection from './components/SkillsSection';
import ProjectsSection from './components/ProjectsSection';
import AcademicJourneySection from './components/AcademicJourneySection';
import ContactSection from './components/ContactSection';

function App() {
  return (
    <div className="app-container">
      <Navbar />
      <HeroSection />
      <AboutSection />
      <SkillsSection />
      <ProjectsSection />
      <AcademicJourneySection />
      <ContactSection />
    </div>
  );
}

export default App;
