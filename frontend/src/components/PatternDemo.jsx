function PatternDemo({ pattern, onCreatePlant, onClonePlant, onChangeState, plants, onDecoratePlant, onSetStrategy, onCreateArrangement }) {
  const plantTypes = ['rose', 'cactus', 'succulent', 'lavender', 'baobab']
  const states = ['seedling', 'growing', 'mature', 'flowering', 'dormant']
  const strategies = [
    { value: 'frequent', label: 'Frequent (Daily)', desc: 'For tropical plants' },
    { value: 'moderate', label: 'Moderate (2-3x/week)', desc: 'For most plants' },
    { value: 'minimal', label: 'Minimal (Weekly)', desc: 'For cacti/succulents' }
  ]

  const patternTitles = {
    factory: '🏭 Factory Pattern',
    prototype: '🧬 Prototype Pattern',
    builder: '🔨 Builder Pattern',
    composite: '🌳 Composite Pattern',
    decorator: '🎨 Decorator Pattern',
    adapter: '🔌 Adapter Pattern',
    iterator: '🔄 Iterator Pattern',
    template: '📋 Template Pattern',
    strategy: '⚡ Strategy Pattern',
    state: '🔄 State Pattern',
    command: '📨 Command Pattern'
  }

  return (
    <div className="pattern-demo">
      <h2>{patternTitles[pattern]}</h2>

      {pattern === 'factory' && (
        <div className="demo-content">
          <p>Create different types of plants using specialized factories.</p>
          <div className="button-grid">
            {plantTypes.map(type => (
              <button key={type} onClick={() => onCreatePlant(type)} className="plant-button">
                Create {type.charAt(0).toUpperCase() + type.slice(1)}
              </button>
            ))}
          </div>
          <div className="pattern-info">
            <h3>Benefits:</h3>
            <ul>
              <li>Encapsulates object creation logic</li>
              <li>Easy to add new plant types</li>
              <li>Each factory handles specific initialization</li>
            </ul>
          </div>
        </div>
      )}

      {pattern === 'prototype' && (
        <div className="demo-content">
          <p>Clone existing plants for propagation.</p>
          {plants.length === 0 ? (
            <p className="warning">Create some plants first using the Factory pattern!</p>
          ) : (
            <div className="clone-list">
              {plants.map(plant => (
                <div key={plant.id} className="clone-item">
                  <span>{plant.type} (ID: {plant.id})</span>
                  <button onClick={() => onClonePlant(plant.id)}>Clone</button>
                </div>
              ))}
            </div>
          )}
          <div className="pattern-info">
            <h3>Benefits:</h3>
            <ul>
              <li>Fast object creation by copying</li>
              <li>Maintains characteristics of original</li>
              <li>Perfect for plant propagation</li>
            </ul>
          </div>
        </div>
      )}

      {pattern === 'composite' && (
        <div className="demo-content">
          <p>View the hierarchical greenhouse structure.</p>
          <div className="composite-tree">
            <div className="tree-node">
              <strong>🏢 NJD Films Greenhouse</strong>
              <div className="tree-children">
                <div className="tree-node">
                  🌴 Tropical Section
                  <div className="tree-children">
                    <div className="tree-node">📦 Shelf 1</div>
                  </div>
                </div>
                <div className="tree-node">
                  🌵 Desert Section
                  <div className="tree-children">
                    <div className="tree-node">📦 Shelf 2</div>
                  </div>
                </div>
              </div>
            </div>
          </div>
          <div className="pattern-info">
            <h3>Benefits:</h3>
            <ul>
              <li>Treats objects and compositions uniformly</li>
              <li>Easy to add new components</li>
              <li>Simplifies client code</li>
            </ul>
          </div>
        </div>
      )}

      {pattern === 'state' && (
        <div className="demo-content">
          <p>Change plant lifecycle states dynamically.</p>
          {plants.length === 0 ? (
            <p className="warning">Create some plants first using the Factory pattern!</p>
          ) : (
            <div className="state-controls">
              {plants.slice(0, 3).map(plant => (
                <div key={plant.id} className="state-item">
                  <h4>{plant.type} (ID: {plant.id})</h4>
                  <div className="state-buttons">
                    {states.map(state => (
                      <button
                        key={state}
                        onClick={() => onChangeState(plant.id, state)}
                        className="state-button"
                      >
                        {state}
                      </button>
                    ))}
                  </div>
                </div>
              ))}
            </div>
          )}
          <div className="pattern-info">
            <h3>Benefits:</h3>
            <ul>
              <li>Localizes state-specific behavior</li>
              <li>Makes state transitions explicit</li>
              <li>Eliminates large conditionals</li>
            </ul>
          </div>
        </div>
      )}

      {pattern === 'builder' && (
        <div className="demo-content">
          <p>Build complex plant arrangements with multiple steps.</p>
          {plants.length === 0 ? (
            <p className="warning">Create some plants first using the Factory pattern!</p>
          ) : (
            <div className="button-grid">
              <button
                onClick={() => onCreateArrangement('gift')}
                className="plant-button"
              >
                Create Gift Arrangement
              </button>
              <button
                onClick={() => onCreateArrangement('landscape')}
                className="plant-button"
              >
                Create Landscape Arrangement
              </button>
            </div>
          )}
          <div className="pattern-info">
            <h3>Benefits:</h3>
            <ul>
              <li>Constructs complex objects step-by-step</li>
              <li>Different builders create different arrangements</li>
              <li>Director orchestrates the building process</li>
              <li>Separates construction from representation</li>
            </ul>
          </div>
        </div>
      )}

      {pattern === 'decorator' && (
        <div className="demo-content">
          <p>Dynamically add decorations to plants to enhance their value and presentation.</p>
          {plants.length === 0 ? (
            <p className="warning">Create some plants first using the Factory pattern!</p>
          ) : (
            <div className="clone-list">
              {plants.map(plant => (
                <div key={plant.id} className="clone-item">
                  <span>{plant.type} (ID: {plant.id})</span>
                  <div style={{display: 'flex', gap: '0.5rem'}}>
                    <label style={{display: 'flex', alignItems: 'center', fontSize: '0.9rem'}}>
                      <input
                        type="checkbox"
                        id={`pot-${plant.id}`}
                        style={{marginRight: '0.3rem'}}
                      /> Pot
                    </label>
                    <label style={{display: 'flex', alignItems: 'center', fontSize: '0.9rem'}}>
                      <input
                        type="checkbox"
                        id={`wrap-${plant.id}`}
                        style={{marginRight: '0.3rem'}}
                      /> Gift Wrap
                    </label>
                    <label style={{display: 'flex', alignItems: 'center', fontSize: '0.9rem'}}>
                      <input
                        type="checkbox"
                        id={`card-${plant.id}`}
                        style={{marginRight: '0.3rem'}}
                      /> Card
                    </label>
                    <button onClick={() => {
                      const decorations = [];
                      if (document.getElementById(`pot-${plant.id}`).checked) decorations.push('pot');
                      if (document.getElementById(`wrap-${plant.id}`).checked) decorations.push('wrapping');
                      if (document.getElementById(`card-${plant.id}`).checked) decorations.push('card');
                      if (decorations.length > 0) {
                        onDecoratePlant(plant.id, decorations);
                      }
                    }}>Apply</button>
                  </div>
                </div>
              ))}
            </div>
          )}
          <div className="pattern-info">
            <h3>Benefits:</h3>
            <ul>
              <li>Adds features dynamically without modifying plant class</li>
              <li>Decorations can be stacked (pot + wrap + card)</li>
              <li>Each decoration adds to the total price</li>
            </ul>
          </div>
        </div>
      )}

      {pattern === 'adapter' && (
        <div className="demo-content">
          <p>Integrates legacy irrigation systems with modern greenhouse controllers.</p>
          <div className="pattern-info">
            <h3>Integration:</h3>
            <ul>
              <li>LegacyIrrigationSystem - Old watering system</li>
              <li>WateringAdapter - Converts modern calls to legacy format</li>
              <li>GreenhouseController - Modern control interface</li>
              <li>Makes incompatible interfaces work together</li>
            </ul>
            <p style={{marginTop: '1rem', color: '#666', fontStyle: 'italic'}}>
              💡 Pattern demonstrated in backend code structure
            </p>
          </div>
        </div>
      )}

      {pattern === 'iterator' && (
        <div className="demo-content">
          <p>Traverse plant inventory without exposing internal structure.</p>
          <div className="pattern-info">
            <h3>Components:</h3>
            <ul>
              <li>InventoryIterator - Provides sequential access</li>
              <li>GreenhouseInventory - Stores plant collection</li>
              <li>InventoryManager - Manages inventory operations</li>
              <li>Abstracts collection traversal</li>
            </ul>
            <p style={{marginTop: '1rem', color: '#666', fontStyle: 'italic'}}>
              💡 Pattern demonstrated in backend code structure
            </p>
          </div>
        </div>
      )}

      {pattern === 'template' && (
        <div className="demo-content">
          <p>Defines skeleton of plant care routines with customizable steps.</p>
          <div className="pattern-info">
            <h3>Care Procedures:</h3>
            <ul>
              <li>RoseCare - Specialized care for roses</li>
              <li>SucculentCare - Specialized care for succulents</li>
              <li>TreeCare - Specialized care for trees</li>
              <li>Common algorithm structure with variable steps</li>
            </ul>
            <p style={{marginTop: '1rem', color: '#666', fontStyle: 'italic'}}>
              💡 Pattern demonstrated in backend code structure
            </p>
          </div>
        </div>
      )}

      {pattern === 'strategy' && (
        <div className="demo-content">
          <p>Select different watering strategies for each plant based on its needs.</p>
          {plants.length === 0 ? (
            <p className="warning">Create some plants first using the Factory pattern!</p>
          ) : (
            <div className="state-controls">
              {plants.slice(0, 3).map(plant => (
                <div key={plant.id} className="state-item">
                  <h4>{plant.type} (ID: {plant.id})</h4>
                  <div className="state-buttons">
                    {strategies.map(strategy => (
                      <button
                        key={strategy.value}
                        onClick={() => onSetStrategy(plant.id, strategy.value)}
                        className="state-button"
                        title={strategy.desc}
                      >
                        {strategy.label}
                      </button>
                    ))}
                  </div>
                </div>
              ))}
            </div>
          )}
          <div className="pattern-info">
            <h3>Benefits:</h3>
            <ul>
              <li>Encapsulates watering algorithms</li>
              <li>Strategies can be swapped at runtime</li>
              <li>Easy to add new strategies without changing plant code</li>
            </ul>
          </div>
        </div>
      )}

      {pattern === 'command' && (
        <div className="demo-content">
          <p>Encapsulate staff tasks as objects for scheduling and execution.</p>
          <div className="pattern-info">
            <h3>Staff Commands:</h3>
            <ul>
              <li>WaterPlantsCommand - Water all plants</li>
              <li>FertilizePlantsCommand - Fertilize plants</li>
              <li>PrunePlantsCommand - Prune plants</li>
              <li>TaskScheduler - Queues and executes commands</li>
              <li>PlantCareStaff & SalesStaff - Command receivers</li>
            </ul>
            <p style={{marginTop: '1rem', color: '#666', fontStyle: 'italic'}}>
              💡 Pattern demonstrated in backend code structure
            </p>
          </div>
        </div>
      )}
    </div>
  )
}

export default PatternDemo
