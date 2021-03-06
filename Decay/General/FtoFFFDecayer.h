// -*- C++ -*-
#ifndef HERWIG_FtoFFFDecayer_H
#define HERWIG_FtoFFFDecayer_H
//
// This is the declaration of the FtoFFFDecayer class.
//

#include "GeneralThreeBodyDecayer.h"
#include "ThePEG/Helicity/Vertex/AbstractFFSVertex.h"
#include "ThePEG/Helicity/Vertex/AbstractFFVVertex.h"
#include "ThePEG/Helicity/Vertex/AbstractFFTVertex.h"

namespace Herwig {
using namespace ThePEG;

/**
 * The FtoFFFDecayer class provides the general matrix elements for the
 * decay of a (anti)fermion to three (anti)fermions.
 *
 * @see \ref FtoFFFDecayerInterfaces "The interfaces"
 * defined for FtoFFFDecayer.
 */
class FtoFFFDecayer: public GeneralThreeBodyDecayer {

public:

  /**
   * Return the matrix element squared for a given mode and phase-space channel
   * @param ichan The channel we are calculating the matrix element for.
   * @param part The decaying Particle.
   * @param decay The particles produced in the decay.
   * @param meopt Option for the matrix element
   * @return The matrix element squared for the phase-space configuration.
   */
  virtual double me2(const int ichan, const Particle & part,
		     const ParticleVector & decay, MEOption meopt) const;
  
  /**
   * Method to return an object to calculate the 3 (or higher body) partial width
   * @param dm The DecayMode
   * @return A pointer to a WidthCalculatorBase object capable of calculating the width
   */
  virtual WidthCalculatorBasePtr threeBodyMEIntegrator(const DecayMode & dm) const;

public:

  /** @name Functions used by the persistent I/O system. */
  //@{
  /**
   * Function used to write out object persistently.
   * @param os the persistent output stream written to.
   */  void persistentOutput(PersistentOStream & os) const;

  /**
   * Function used to read in object persistently.
   * @param is the persistent input stream read from.
   * @param version the version number of the object when written.
   */
  void persistentInput(PersistentIStream & is, int version);
  //@}

  /**
   * The standard Init function used to initialize the interfaces.
   * Called exactly once for each class by the class description system
   * before the main function starts or
   * when this class is dynamically loaded.
   */
  static void Init();

protected:

  /** @name Clone Methods. */
  //@{
  /**
   * Make a simple clone of this object.
   * @return a pointer to the new object.
   */
  virtual IBPtr clone() const;

  /** Make a clone of this object, possibly modifying the cloned object
   * to make it sane.
   * @return a pointer to the new object.
   */
  virtual IBPtr fullclone() const;
  //@}

protected:

  /** @name Standard Interfaced functions. */
  //@{
  /**
   * Initialize this object after the setup phase before saving an
   * EventGenerator to disk.
   * @throws InitException if object could not be initialized properly.
   */
  virtual void doinit();
  //@}

private:

  /**
   * The static object used to initialize the description of this class.
   * Indicates that this is a concrete class with persistent data.
   */
  static ClassDescription<FtoFFFDecayer> initFtoFFFDecayer;

  /**
   * The assignment operator is private and must never be called.
   * In fact, it should not even be implemented.
   */
  FtoFFFDecayer & operator=(const FtoFFFDecayer &);

private:
  
  /**
   * Store the vector of FFSVertex pairs
   */
  vector<pair<AbstractFFSVertexPtr, AbstractFFSVertexPtr> > _sca;

  /**
   * Store the vector of FFVVertex pairs
   */
  vector<pair<AbstractFFVVertexPtr, AbstractFFVVertexPtr> > _vec;

  /**
   * Store the vector of FFTVertex pairs
   */
  vector<pair<AbstractFFTVertexPtr, AbstractFFTVertexPtr> > _ten;

  /**
   *  Spin density matrix 
   */
  mutable RhoDMatrix _rho;

  /**
   *  Spinors for incoming particle
   */
  mutable pair<vector<SpinorWaveFunction>,vector<SpinorBarWaveFunction> > _inwave;

  /**
   *  Spinors for outgoing particles
   */
  mutable pair<vector<SpinorWaveFunction>,vector<SpinorBarWaveFunction> > _outwave[3];
};

}

#include "ThePEG/Utilities/ClassTraits.h"

namespace ThePEG {

/** @cond TRAITSPECIALIZATIONS */

/** This template specialization informs ThePEG about the
 *  base classes of FtoFFFDecayer. */
template <>
struct BaseClassTrait<Herwig::FtoFFFDecayer,1> {
  /** Typedef of the first base class of FtoFFFDecayer. */
  typedef Herwig::GeneralThreeBodyDecayer NthBase;
};

/** This template specialization informs ThePEG about the name of
 *  the FtoFFFDecayer class and the shared object where it is defined. */
template <>
struct ClassTraits<Herwig::FtoFFFDecayer>
  : public ClassTraitsBase<Herwig::FtoFFFDecayer> {
  /** Return a platform-independent class name */
  static string className() { return "Herwig::FtoFFFDecayer"; }
};

/** @endcond */

}


#endif /* HERWIG_FtoFFFDecayer_H */
