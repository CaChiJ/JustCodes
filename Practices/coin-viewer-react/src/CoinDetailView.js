export function CoinDetailView({ coin }) {
    return (
        <div>
            <h1>{ coin.name }</h1>
            <p>Rank: { coin.rank }</p>
            <p>Symbol: { coin.symbol }</p>
            <p>Price: { coin.quotes.USD.price }</p>
            <p>Market cap: { coin.quotes.USD.market_cap }</p>
            <p>Volume: { coin.quotes.USD.volume_24h }</p>
            <p>Percent change 1h: { coin.quotes.USD.percent_change_1h }</p>
            <p>Percent change 24h: { coin.quotes.USD.percent_change_24h }</p>
            <p>Percent change 7d: { coin.quotes.USD.percent_change_7d }</p>
        </div>
    );
}