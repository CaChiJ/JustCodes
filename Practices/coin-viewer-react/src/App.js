import { useEffect, useState } from "react";

import styles from "./App.module.css";
import { CoinDetailView } from "./CoinDetailView";
import { CoinList } from "./CoinList";

function App() {
  const [coins, setCoins] = useState([]);
  const [selectedCoin, setSelectedCoin] = useState(null);
  const [isLoading, setIsLoading] = useState(true);
  
  useEffect(() => {
    fetch("https://api.coinpaprika.com/v1/tickers")
      .then((response) => response.json())
      .then((json) => {
        setCoins(json);
        setIsLoading(false);
      })
  }, []);

  const onSelect = (event) => {
    if (event.target.value === null) {
      setSelectedCoin(null);
    } else {
      setSelectedCoin(coins[event.target.value]);
    }
  }

  return (
    <div className="App">
      <header className={ styles.header }>
        <span className={ styles.appTitle }>Coin viewer</span>
        <span className={ styles.appAuthor }>made by Hyunjun Choi</span>
      </header>
      <hr/>
      {isLoading ? 
        "Loading..." : 
        (
          <div>
            <CoinList coins={ coins } onSelect={ onSelect } />
            {selectedCoin === null ?
              "select a coin" :
              <CoinDetailView coin={ selectedCoin } />
            }
          </div>
        )
      }
      
    </div>
  );
}

export default App;
