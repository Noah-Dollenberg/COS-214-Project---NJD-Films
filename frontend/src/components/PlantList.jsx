function PlantList({ plants }) {
  const getPlantEmoji = (type) => {
    const emojis = {
      'Rose': '🌹',
      'Cactus': '🌵',
      'Succulent': '🪴',
      'Lavender': '💜',
      'Baobab': '🌳'
    }
    return emojis[type] || '🌱'
  }

  const getHealthColor = (health) => {
    if (health >= 80) return '#4caf50'
    if (health >= 50) return '#ff9800'
    return '#f44336'
  }

  return (
    <div className="plant-list">
      <h2>Plant Inventory ({plants.length})</h2>
      {plants.length === 0 ? (
        <p className="empty-state">No plants yet. Create some using the Factory pattern!</p>
      ) : (
        <div className="plant-cards">
          {plants.map(plant => (
            <div key={plant.id} className="plant-card">
              <div className="plant-emoji">{getPlantEmoji(plant.type)}</div>
              <div className="plant-info">
                <h3>{plant.type}</h3>
                <p>ID: {plant.id}</p>
                <p>Price: R{plant.price.toFixed(2)}</p>
                <div className="health-bar">
                  <div
                    className="health-fill"
                    style={{
                      width: `${plant.health}%`,
                      backgroundColor: getHealthColor(plant.health)
                    }}
                  />
                  <span className="health-text">{plant.health}%</span>
                </div>
              </div>
            </div>
          ))}
        </div>
      )}
    </div>
  )
}

export default PlantList
