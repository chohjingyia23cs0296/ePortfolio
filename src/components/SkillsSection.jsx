import React from 'react';
import { motion } from 'framer-motion';
import { Cloud, Globe, Database, Code2, Award } from 'lucide-react';

const fadeInUp = {
  hidden: { opacity: 0, y: 30 },
  visible: {
    opacity: 1,
    y: 0,
    transition: { duration: 0.6, ease: [0.16, 1, 0.3, 1] },
  },
};

const categories = [
  {
    title: 'Cloud & Data Architecture',
    icon: Cloud,
    skills: [
      'Microsoft Azure',
      'Azure Data Factory',
      'Databricks',
      'Synapse Analytics',
      'AWS',
      'Medallion Architecture',
      'ETL Automation',
    ],
  },
  {
    title: 'Software & Web Development',
    icon: Globe,
    skills: ['React', 'Vite', 'Node.js', 'Express.js', 'SAPUI5', 'MVC Architecture', 'HTML/CSS'],
  },
  {
    title: 'Databases',
    icon: Database,
    skills: ['PostgreSQL', 'MongoDB', 'MySQL', 'Firebase', 'SQL Server'],
  },
  {
    title: 'Programming Languages',
    icon: Code2,
    skills: ['Python', 'SQL', 'JavaScript', 'C++', 'Java', 'Dart', 'PHP'],
  },
];

const certifications = [
  { name: 'AWS Cloud Data Pipeline Builder', icon: '☁️' },
  { name: 'Microsoft Azure Data Fundamentals', icon: '📊' },
];

const SkillsSection = () => {
  return (
    <section id="skills" className="section">
      <div className="container">
        <motion.div
          className="section-header"
          initial="hidden"
          whileInView="visible"
          viewport={{ once: true, margin: '-100px' }}
          variants={fadeInUp}
        >
          <span className="section-label">
            <Award size={14} /> Skills & Expertise
          </span>
          <h2 className="section-title" style={{ textAlign: 'center' }}>
            Technologies I Work With
          </h2>
        </motion.div>

        {/* Certifications */}
        <motion.div
          className="certifications-row"
          initial="hidden"
          whileInView="visible"
          viewport={{ once: true, margin: '-50px' }}
          variants={{
            visible: { transition: { staggerChildren: 0.1 } },
          }}
        >
          {certifications.map((cert, idx) => (
            <motion.div
              key={idx}
              className="cert-badge"
              variants={{
                hidden: { opacity: 0, scale: 0.9 },
                visible: { opacity: 1, scale: 1, transition: { duration: 0.4 } },
              }}
            >
              <span style={{ fontSize: '1.2rem' }}>{cert.icon}</span>
              {cert.name}
            </motion.div>
          ))}
        </motion.div>

        {/* Skill Cards — Bento Grid */}
        <motion.div
          className="grid-2"
          initial="hidden"
          whileInView="visible"
          viewport={{ once: true, margin: '-80px' }}
          variants={{
            visible: { transition: { staggerChildren: 0.12 } },
          }}
        >
          {categories.map((cat, idx) => (
            <motion.div
              key={idx}
              className="card"
              variants={{
                hidden: { opacity: 0, y: 25 },
                visible: {
                  opacity: 1,
                  y: 0,
                  transition: { duration: 0.5, ease: [0.16, 1, 0.3, 1] },
                },
              }}
            >
              <div className="card-accent"></div>
              <div className="skill-card-header">
                <div className="skill-card-icon">
                  <cat.icon size={22} />
                </div>
                <h3 className="skill-card-title">{cat.title}</h3>
              </div>
              <div className="skill-tags">
                {cat.skills.map((skill, i) => (
                  <span key={i} className="tag">
                    {skill}
                  </span>
                ))}
              </div>
            </motion.div>
          ))}
        </motion.div>
      </div>
    </section>
  );
};

export default SkillsSection;
