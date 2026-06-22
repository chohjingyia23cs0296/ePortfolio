import React from 'react';
import { motion } from 'framer-motion';
import { Database, Cloud, Server, BarChart3 } from 'lucide-react';

const LinkedInIcon = () => (
  <svg viewBox="0 0 24 24" width="18" height="18" fill="currentColor" xmlns="http://www.w3.org/2000/svg">
    <path d="M20.447 20.452h-3.554v-5.569c0-1.328-.027-3.037-1.852-3.037-1.853 0-2.136 1.445-2.136 2.939v5.667H9.351V9h3.414v1.561h.046c.477-.9 1.637-1.85 3.37-1.85 3.601 0 4.267 2.37 4.267 5.455v6.286zM5.337 7.433a2.062 2.062 0 0 1-2.063-2.065 2.064 2.064 0 1 1 2.063 2.065zm1.782 13.019H3.555V9h3.564v11.452zM22.225 0H1.771C.792 0 0 .774 0 1.729v20.542C0 23.227.792 24 1.771 24h20.451C23.2 24 24 23.227 24 22.271V1.729C24 .774 23.2 0 22.222 0h.003z" />
  </svg>
);

const fadeInUp = {
  hidden: { opacity: 0, y: 30 },
  visible: (i = 0) => ({
    opacity: 1,
    y: 0,
    transition: { duration: 0.6, delay: i * 0.15, ease: [0.16, 1, 0.3, 1] },
  }),
};

const HeroSection = () => {
  return (
    <section className="hero section" id="hero">
      {/* Background blobs */}
      <div className="hero-blob hero-blob-1"></div>
      <div className="hero-blob hero-blob-2"></div>

      <div className="container">
        <div className="hero-content">
          {/* Left — Text */}
          <motion.div
            initial="hidden"
            animate="visible"
            variants={{ visible: { transition: { staggerChildren: 0.15 } } }}
          >
            <motion.p className="hero-greeting" variants={fadeInUp} custom={0}>
              👋 Hello, I'm
            </motion.p>

            <motion.h1 className="hero-name" variants={fadeInUp} custom={1}>
              Choh <span className="gradient-text">Jing Yi</span>
            </motion.h1>

            <motion.h2 className="hero-role" variants={fadeInUp} custom={2}>
              Data Engineering Student @ UTM
            </motion.h2>

            <motion.p className="hero-description" variants={fadeInUp} custom={3}>
              Building enterprise data pipelines, cloud infrastructure, and
              intelligent software to solve complex, real-world problems.
            </motion.p>

            <motion.div className="hero-actions" variants={fadeInUp} custom={4}>
              <a href="#projects" className="btn btn-primary">
                View Projects
              </a>
              <a
                href="https://github.com/chohjingyia23cs0296"
                target="_blank"
                rel="noreferrer"
                className="btn btn-outline"
              >
                GitHub Profile
              </a>
              <a
                href="https://www.linkedin.com/in/chohjingyi"
                target="_blank"
                rel="noreferrer"
                className="btn btn-outline"
              >
                <LinkedInIcon />
                LinkedIn
              </a>
            </motion.div>
          </motion.div>

          {/* Right — Abstract Visual */}
          <motion.div
            className="hero-visual"
            initial={{ opacity: 0, scale: 0.85 }}
            animate={{ opacity: 1, scale: 1 }}
            transition={{ duration: 0.8, delay: 0.3, ease: [0.16, 1, 0.3, 1] }}
          >
            <div className="hero-abstract">
              <div className="ring ring-1"></div>
              <div className="ring ring-2"></div>
              <div className="ring ring-3"></div>
              <div className="core"></div>

              {/* Floating tech icons */}
              <div className="float-icon">
                <Database size={24} color="#6366F1" />
              </div>
              <div className="float-icon">
                <Cloud size={24} color="#8B5CF6" />
              </div>
              <div className="float-icon">
                <Server size={24} color="#A855F7" />
              </div>
              <div className="float-icon">
                <BarChart3 size={24} color="#6366F1" />
              </div>
            </div>
          </motion.div>
        </div>
      </div>
    </section>
  );
};

export default HeroSection;
