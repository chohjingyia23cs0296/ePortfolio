import React from 'react';
import { motion } from 'framer-motion';
import { Database, CreditCard, Warehouse, Users, ExternalLink } from 'lucide-react';

const fadeInUp = {
  hidden: { opacity: 0, y: 30 },
  visible: {
    opacity: 1,
    y: 0,
    transition: { duration: 0.6, ease: [0.16, 1, 0.3, 1] },
  },
};

const projects = [
  {
    title: 'Azure End-to-End Data Engineering Pipeline',
    type: 'Coursework Project, 2026',
    description:
      'Designed an end-to-end ETL pipeline on Microsoft Azure (Data Factory, Databricks, Synapse Analytics) to ingest and transform on-premises customer and sales data through a Medallion Architecture, enabling data-driven decision making via an interactive Power BI dashboard.',
    tags: ['Azure Data Factory', 'Databricks', 'Synapse Analytics', 'Power BI'],
    icon: Database,
    gradient: 'linear-gradient(135deg, #6366F1, #818CF8)',
    repoUrl: 'https://github.com/chohjingyia23cs0296/medallion_architecture',
  },
  {
    title: 'Hostel Payment & Billing System',
    type: 'Coursework Project, 2025',
    description:
      'Developed a cloud-native web application on SAP BTP using SAPUI5 and MVC architecture, automating student billing workflows and receipt generation for hostel management.',
    tags: ['SAP BTP', 'SAPUI5', 'MVC'],
    icon: CreditCard,
    gradient: 'linear-gradient(135deg, #8B5CF6, #A78BFA)',
    repoUrl: 'https://github.com/chohjingyia23cs0296/Payment-and-Billing-System-',
  },
  {
    title: 'SQL Data Warehouse',
    type: 'Personal Project, 2026',
    description:
      'Built a multi-layer SQL Data Warehouse using SQL Server and SSMS, reducing manual data processing by automating ETL pipelines and centralising CRM data into a Star Schema for faster querying.',
    tags: ['SQL Server', 'SSMS', 'ETL', 'Star Schema'],
    icon: Warehouse,
    gradient: 'linear-gradient(135deg, #A855F7, #C084FC)',
    repoUrl: 'https://github.com/chohjingyia23cs0296/sql-data-warehouse-project',
  },
  {
    title: 'Wello System (AI Onboarding Platform)',
    type: 'UTM Hackathon, 2025',
    description:
      'Led a development team to build an AI-powered employee onboarding platform using React, Vite, Node.js, Express.js, and PostgreSQL, streamlining new hire integration workflows.',
    tags: ['React', 'Node.js', 'Express.js', 'PostgreSQL'],
    icon: Users,
    gradient: 'linear-gradient(135deg, #6366F1, #8B5CF6)',
    repoUrl: 'https://github.com/chohjingyia23cs0296/utmhackathon25',
  },
];

const ProjectsSection = () => {
  return (
    <section id="projects" className="section" style={{ background: 'var(--bg-tertiary)' }}>
      <div className="container">
        <motion.div
          className="section-header"
          initial="hidden"
          whileInView="visible"
          viewport={{ once: true, margin: '-100px' }}
          variants={fadeInUp}
        >
          <span className="section-label">Portfolio</span>
          <h2 className="section-title" style={{ textAlign: 'center' }}>
            Featured Projects
          </h2>
          <p className="section-subtitle" style={{ textAlign: 'center' }}>
            A collection of data engineering and software projects I've built throughout my academic journey.
          </p>
        </motion.div>

        <motion.div
          className="grid-2"
          initial="hidden"
          whileInView="visible"
          viewport={{ once: true, margin: '-80px' }}
          variants={{
            visible: { transition: { staggerChildren: 0.12 } },
          }}
        >
          {projects.map((project, idx) => (
            <motion.div
              key={idx}
              className="card project-card"
              variants={{
                hidden: { opacity: 0, y: 25 },
                visible: {
                  opacity: 1,
                  y: 0,
                  transition: { duration: 0.5, ease: [0.16, 1, 0.3, 1] },
                },
              }}
            >
              {/* Gradient Header */}
              <div
                className="project-card-header"
                style={{ background: project.gradient }}
              >
                <project.icon className="project-icon" size={56} strokeWidth={1.5} />
              </div>

              <div className="project-type">{project.type}</div>
              <h3 className="project-title">{project.title}</h3>
              <p className="project-description">{project.description}</p>

              <div className="project-tags">
                {project.tags.map((tag, i) => (
                  <span key={i} className="tag">
                    {tag}
                  </span>
                ))}
              </div>

              {project.repoUrl && (
                <a
                  href={project.repoUrl}
                  target="_blank"
                  rel="noreferrer"
                  className="project-repo-link"
                >
                  <ExternalLink size={14} />
                  View on GitHub
                </a>
              )}
            </motion.div>
          ))}
        </motion.div>
      </div>
    </section>
  );
};

export default ProjectsSection;
