// -*- C++ -*-
#ifndef HERWIG_QQHiggsProcessConstructor_H
#define HERWIG_QQHiggsProcessConstructor_H
//
// This is the declaration of the QQHiggsProcessConstructor class.
//

#include "HardProcessConstructor.h"

namespace Herwig {

using namespace ThePEG;

/**
 * Here is the documentation of the QQHiggsProcessConstructor class.
 *
 * @see \ref QQHiggsProcessConstructorInterfaces "The interfaces"
 * defined for QQHiggsProcessConstructor.
 */
class QQHiggsProcessConstructor: public HardProcessConstructor {

public:

  /**
   * The default constructor.
   */
  QQHiggsProcessConstructor();

  /**
   * Main function called to start constructing the diagrams for 
   * the 2->2 process
   */
  void constructDiagrams();

public:

  /** @name Functions used by the persistent I/O system. */
  //@{
  /**
   * Function used to write out object persistently.
   * @param os the persistent output stream written to.
   */
  void persistentOutput(PersistentOStream & os) const;

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

private:

  /**
   * The assignment operator is private and must never be called.
   * In fact, it should not even be implemented.
   */
  QQHiggsProcessConstructor & operator=(const QQHiggsProcessConstructor &);

private:

  /**
   * Which partonic processes to include 
   */
  unsigned int _process;

  /**
   *  Which outgoing quark flavours to include
   */
  unsigned int _quarkFlavour;

  /**
   *  The outgoing higgs bosons
   */
  PDVector _higgs;

  /**
   *  Treatment of the Higgs width
   */
  unsigned int _shapeOpt;
};

}

#endif /* HERWIG_QQHiggsProcessConstructor_H */
