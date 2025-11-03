function GreenhouseView({ plants }) {
  return (
    <div className="greenhouse-view">
      <h2>Greenhouse Visualization</h2>
      <div className="greenhouse-container">
        <div className="greenhouse-roof">
          <div className="roof-left"></div>
          <div className="roof-right"></div>
        </div>
        <div className="greenhouse-body">
          <div className="greenhouse-section">
            <h3>🌴 Tropical</h3>
            <div className="shelf">
              {plants.slice(0, Math.ceil(plants.length / 2)).map((plant, idx) => (
                <div key={idx} className="plant-slot" title={`${plant.type} (ID: ${plant.id})`}>
                  🌱
                </div>
              ))}
            </div>
          </div>
          <div className="greenhouse-section">
            <h3>🌵 Desert</h3>
            <div className="shelf">
              {plants.slice(Math.ceil(plants.length / 2)).map((plant, idx) => (
                <div key={idx} className="plant-slot" title={`${plant.type} (ID: ${plant.id})`}>
                  🌱
                </div>
              ))}
            </div>
          </div>
        </div>
      </div>
      <div className="stats">
        <p>Total Plants: {plants.length}</p>
        <p>Tropical Section: {Math.ceil(plants.length / 2)}</p>
        <p>Desert Section: {Math.floor(plants.length / 2)}</p>
      </div>
    </div>
  )
}

export default GreenhouseView
