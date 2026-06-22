import React from 'react';
import { motion } from 'framer-motion';
import { Database, Cloud, Server, BarChart3 } from 'lucide-react';

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
