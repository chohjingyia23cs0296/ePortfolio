import React from 'react';
import { motion } from 'framer-motion';
import { GraduationCap, Award, FolderKanban } from 'lucide-react';

const fadeInUp = {
  hidden: { opacity: 0, y: 30 },
  visible: {
    opacity: 1,
    y: 0,
    transition: { duration: 0.6, ease: [0.16, 1, 0.3, 1] },
  },
};

const stats = [
  { icon: GraduationCap, value: '3.99', label: 'CGPA / 4.00' },
  { icon: FolderKanban, value: '4+', label: 'Projects Built' },
  { icon: Award, value: '2', label: 'Certifications' },
];

const AboutSection = () => {
  return (
    <section id="about" className="section" style={{ background: 'var(--bg-tertiary)' }}>
      <div className="container">
        <motion.div
          className="section-header"
          initial="hidden"
          whileInView="visible"
          viewport={{ once: true, margin: '-100px' }}
          variants={fadeInUp}
        >
          <span className="section-label">About Me</span>
          <h2 className="section-title" style={{ textAlign: 'center' }}>
            Passionate about Data & Cloud
          </h2>
        </motion.div>

        <div className="about-grid">
          <motion.div
            className="card about-text"
            initial="hidden"
            whileInView="visible"
            viewport={{ once: true, margin: '-100px' }}
            variants={fadeInUp}
          >
            <div className="card-accent"></div>
            <p>
              I am a <strong>Bachelor of Computer Science (Data Engineering)</strong> student
              at Universiti Teknologi Malaysia (UTM) with a CGPA of <strong>3.99/4.00</strong>,
              expected to graduate in September 2027.
            </p>
            <p>
              My academic journey has equipped me with a strong foundation in programming,
              computer systems, and modern data-engineering workflows. I am deeply passionate
              about cloud technologies, data architecture, and AI-powered platforms.
            </p>
            <p>
              Currently, I am seeking opportunities to apply my enterprise data engineering
              and cloud software skills to support large-scale server manufacturing and
              data center infrastructure.
            </p>
          </motion.div>

          <div className="about-stats">
            {stats.map((stat, idx) => (
              <motion.div
                key={idx}
                className="card stat-card"
                initial="hidden"
                whileInView="visible"
                viewport={{ once: true, margin: '-50px' }}
                variants={{
                  hidden: { opacity: 0, y: 20 },
                  visible: {
                    opacity: 1,
                    y: 0,
                    transition: { duration: 0.5, delay: idx * 0.15, ease: [0.16, 1, 0.3, 1] },
                  },
                }}
              >
                <div className="card-accent"></div>
                <stat.icon size={28} color="#6366F1" style={{ margin: '0 auto 0.5rem' }} />
                <div className="stat-value">{stat.value}</div>
                <div className="stat-label">{stat.label}</div>
              </motion.div>
            ))}
          </div>
        </div>
      </div>
    </section>
  );
};

export default AboutSection;
