import React from 'react';
import { motion } from 'framer-motion';
import { BookOpen } from 'lucide-react';

const fadeInUp = {
  hidden: { opacity: 0, y: 30 },
  visible: {
    opacity: 1,
    y: 0,
    transition: { duration: 0.6, ease: [0.16, 1, 0.3, 1] },
  },
};

const journeys = [
  {
    year: 'Year 3 — Current',
    title: 'Applied Data Engineering',
    desc: 'Connects earlier programming and database knowledge with artificial intelligence, enterprise systems, mobile development, business intelligence, high-performance processing, cloud technologies, and analytical pipelines.',
  },
  {
    year: 'Year 2',
    title: 'Software, Databases & Data Analysis',
    desc: 'Expanded into algorithms, databases, networking, software engineering, web-system development, Python analytics, data mining, Java programming, and operating-system concepts.',
  },
  {
    year: 'Year 1',
    title: 'Computing Foundations',
    desc: 'Introduced programming, digital systems, computer architecture, interface design, information systems, and system analysis. Established foundation in C++, logical problem solving, low-level computing concepts, user-centred design, and technical documentation.',
  },
];

const AcademicJourneySection = () => {
  return (
    <section id="academic" className="section">
      <div className="container">
        <motion.div
          className="section-header"
          initial="hidden"
          whileInView="visible"
          viewport={{ once: true, margin: '-100px' }}
          variants={fadeInUp}
        >
          <span className="section-label">
            <BookOpen size={14} /> Education
          </span>
          <h2 className="section-title" style={{ textAlign: 'center' }}>
            Academic Journey
          </h2>
          <p className="section-subtitle" style={{ textAlign: 'center' }}>
            Bachelor of Computer Science (Data Engineering) with Honours — Universiti Teknologi Malaysia
          </p>
        </motion.div>

        <div className="timeline">
          {journeys.map((item, idx) => (
            <motion.div
              key={idx}
              className="timeline-item"
              initial="hidden"
              whileInView="visible"
              viewport={{ once: true, margin: '-50px' }}
              variants={{
                hidden: { opacity: 0, x: -20 },
                visible: {
                  opacity: 1,
                  x: 0,
                  transition: {
                    duration: 0.6,
                    delay: idx * 0.15,
                    ease: [0.16, 1, 0.3, 1],
                  },
                },
              }}
            >
              <div className="timeline-dot">
                <div className="timeline-dot-inner"></div>
              </div>
              <div className="timeline-card">
                <span className="timeline-year">{item.year}</span>
                <h3 className="timeline-title">{item.title}</h3>
                <p className="timeline-desc">{item.desc}</p>
              </div>
            </motion.div>
          ))}
        </div>
      </div>
    </section>
  );
};

export default AcademicJourneySection;
