import { useState, useEffect } from 'react'
import './App.css'
import PatternDemo from './components/PatternDemo'
import PlantList from './components/PlantList'
import GreenhouseView from './components/GreenhouseView'

const API_BASE = 'http://127.0.0.1:8080/api'

function App() {
  const [plants, setPlants] = useState([])
  const [selectedPattern, setSelectedPattern] = useState('factory')
  const [message, setMessage] = useState('')

  // Fetch plants from backend
  const fetchPlants = async () => {
    try {
      const response = await fetch(`${API_BASE}/plants`)
      const data = await response.json()
      setPlants(data.plants || [])
    } catch (error) {
      console.error('Error fetching plants:', error)
      setMessage('Error connecting to backend server. Is it running?')
    }
  }

  useEffect(() => {
    fetchPlants()
    // Poll for updates every 2 seconds
    const interval = setInterval(fetchPlants, 2000)
    return () => clearInterval(interval)
  }, [])

  const createPlant = async (plantType) => {
    try {
      const response = await fetch(`${API_BASE}/factory/create`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ type: plantType })
      })
      const data = await response.json()
      if (data.success) {
        setMessage(`Created ${data.type} with ID ${data.id}`)
        fetchPlants()
      } else {
        setMessage(data.error || 'Failed to create plant')
      }
    } catch (error) {
      setMessage('Error creating plant: ' + error.message)
    }
  }

  const clonePlant = async (plantId) => {
    try {
      const response = await fetch(`${API_BASE}/prototype/clone`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ id: plantId })
      })
      const data = await response.json()
      if (data.success) {
        setMessage(`Cloned plant ${data.original_id} -> new ID ${data.clone_id}`)
        fetchPlants()
      } else {
        setMessage(data.error || 'Failed to clone plant')
      }
    } catch (error) {
      setMessage('Error cloning plant: ' + error.message)
    }
  }

  const changePlantState = async (plantId, newState) => {
    try {
      const response = await fetch(`${API_BASE}/state/change`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ id: plantId, state: newState })
      })
      const data = await response.json()
      if (data.success) {
        setMessage(`Changed plant ${plantId} to ${newState} state`)
      } else {
        setMessage(data.error || 'Failed to change state')
      }
    } catch (error) {
      setMessage('Error changing state: ' + error.message)
    }
  }

  const decoratePlant = async (plantId, decorations) => {
    try {
      const response = await fetch(`${API_BASE}/decorator/add`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ id: plantId, decorations: decorations })
      })
      const data = await response.json()
      if (data.success) {
        setMessage(`Decorated plant ${plantId}: R${data.price.toFixed(2)} - ${data.description}`)
      } else {
        setMessage(data.error || 'Failed to decorate plant')
      }
    } catch (error) {
      setMessage('Error decorating plant: ' + error.message)
    }
  }

  const setWateringStrategy = async (plantId, strategy) => {
    try {
      const response = await fetch(`${API_BASE}/strategy/set`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ id: plantId, strategy: strategy })
      })
      const data = await response.json()
      if (data.success) {
        setMessage(`Set ${strategy} watering for plant ${plantId}: ${data.description}`)
      } else {
        setMessage(data.error || 'Failed to set strategy')
      }
    } catch (error) {
      setMessage('Error setting strategy: ' + error.message)
    }
  }

  const createArrangement = async (type) => {
    try {
      const response = await fetch(`${API_BASE}/builder/create`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ type: type })
      })
      const data = await response.json()
      if (data.success) {
        setMessage(`Created ${data.name}: ${data.plant_count} plants in ${data.container} - R${data.total_price.toFixed(2)}`)
      } else {
        setMessage(data.error || 'Failed to create arrangement')
      }
    } catch (error) {
      setMessage('Error creating arrangement: ' + error.message)
    }
  }

  return (
    <div className="app">
      <header className="header">
        <h1>🌿 NJD Films Greenhouse Simulation</h1>
        <p>Interactive Design Pattern Showcase</p>
      </header>

      {message && (
        <div className="message-banner">
          {message}
          <button onClick={() => setMessage('')}>✕</button>
        </div>
      )}

      <div className="pattern-selector">
        <h2>🏛️ Design Patterns Gallery</h2>
        <div className="pattern-buttons">
          <button
            className={selectedPattern === 'factory' ? 'active' : ''}
            onClick={() => setSelectedPattern('factory')}
          >
            🏭 Factory
          </button>
          <button
            className={selectedPattern === 'prototype' ? 'active' : ''}
            onClick={() => setSelectedPattern('prototype')}
          >
            🧬 Prototype
          </button>
          <button
            className={selectedPattern === 'builder' ? 'active' : ''}
            onClick={() => setSelectedPattern('builder')}
          >
            🔨 Builder
          </button>
          <button
            className={selectedPattern === 'composite' ? 'active' : ''}
            onClick={() => setSelectedPattern('composite')}
          >
            🌳 Composite
          </button>
          <button
            className={selectedPattern === 'decorator' ? 'active' : ''}
            onClick={() => setSelectedPattern('decorator')}
          >
            🎨 Decorator
          </button>
          <button
            className={selectedPattern === 'adapter' ? 'active' : ''}
            onClick={() => setSelectedPattern('adapter')}
          >
            🔌 Adapter
          </button>
          <button
            className={selectedPattern === 'iterator' ? 'active' : ''}
            onClick={() => setSelectedPattern('iterator')}
          >
            🔄 Iterator
          </button>
          <button
            className={selectedPattern === 'template' ? 'active' : ''}
            onClick={() => setSelectedPattern('template')}
          >
            📋 Template
          </button>
          <button
            className={selectedPattern === 'strategy' ? 'active' : ''}
            onClick={() => setSelectedPattern('strategy')}
          >
            ⚡ Strategy
          </button>
          <button
            className={selectedPattern === 'state' ? 'active' : ''}
            onClick={() => setSelectedPattern('state')}
          >
            🔄 State
          </button>
          <button
            className={selectedPattern === 'command' ? 'active' : ''}
            onClick={() => setSelectedPattern('command')}
          >
            📨 Command
          </button>
        </div>
      </div>

      <div className="main-content">
        <div className="left-panel">
          <PatternDemo
            pattern={selectedPattern}
            onCreatePlant={createPlant}
            onClonePlant={clonePlant}
            onChangeState={changePlantState}
            onDecoratePlant={decoratePlant}
            onSetStrategy={setWateringStrategy}
            onCreateArrangement={createArrangement}
            plants={plants}
          />
        </div>

        <div className="right-panel">
          <PlantList plants={plants} />
          {plants.length > 0 && <GreenhouseView plants={plants} />}
        </div>
      </div>

      <footer className="footer">
        <p>🌿 COS 214 Project - NJD Films Greenhouse Simulation</p>
        <p>Backend: C++ with Boost.Beast | Frontend: React 18 + Vite</p>
        <p style={{fontSize: '0.9rem', opacity: 0.7}}>11 Design Patterns · Interactive Demonstrations · Real-time Updates</p>
      </footer>
    </div>
  )
}

export default App
