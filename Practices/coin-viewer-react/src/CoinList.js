export function CoinList({ coins, onSelect }) {
    return (
        <select onChange={ onSelect }>
            <option value={null}>Select a coin</option>
            {coins.map((coin, index) => (
                <option value={index}>
                    <span>{coin.rank}. {coin.name} ({coin.symbol}) : {coin.quotes.USD.price} USD</span>
                </option>
            ))}
        </select>
    )
}

