/////////////////////////////////////////////////////////////////////////////
// Name:        tuplet.h
// Author:      Rodolfo Zitellini
// Created:     26/06/2012
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////


#ifndef __VRV_TUPLET_H__
#define __VRV_TUPLET_H__

#include "atts_shared.h"
#include "layer.h"
#include "note.h"
#include "object.h"

namespace vrv {

//----------------------------------------------------------------------------
// Tuplet
//----------------------------------------------------------------------------

class Tuplet: public LayerElement, public ObjectListInterface,
    public AttDurationRatio
{
public:
    /**
     * @name Constructors, destructors, and other standard methods
     * Reset method reset all attribute classes
     */
    ///@{
    Tuplet();
    Tuplet(int num, int numbase);
    virtual ~Tuplet();
    virtual void Reset();
    virtual std::string GetClassName( ) { return "Tuplet"; };
    ///@}

	int GetNoteCount() const { return (int)m_children.size(); };
    
    /**
     * Add an element (a note or a rest) to a tuplet.
     * Only Note or Rest elements will be actually added to the beam.
     */
    void AddElement(LayerElement *element);
    
protected:
    /**
     * Filter the list for a specific class.
     * For example, keep only notes in Beam
     */
    virtual void FilterList();
    
private:
    
public:
    
private:

};

} // namespace vrv    
    
#endif