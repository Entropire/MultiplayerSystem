# Network Architectures

## Introduction
In this document, I have compiled my research on various networking architectures used in multiplayer games.

## Types of Network Architectures
- [Client-Server Model](#client-server-model)
- [Listed Client-Server Model](#listed-client-server-model)
- [Peer-to-Peer Model](#peer-to-peer-model)
- [Hybrid Model](#hybrid-model)

## Client-Server Model
<img src="Images/Client-Server-Model.png" alt="Client-Server Model" width="300" height="auto"/>

The client-server model is a network architecture where there is one dedicated central server that manages the game state where multiple clients connect to.

#### pro's
- **Centralized Control:** The server has full control over the game state, ensuring consistency and preventing cheating.
- **Security:** Since the server controls the game logic, it is harder for players to manipulate the game state.
- **Consistency:** All clients receive updates from the same source, reducing the risk of desynchronization.
- **Scalability:** The server can be optimized to handle many clients, making it suitable for large-scale multiplayer games.

#### con's
- **Cost:** Running a dedicated server can be expensive, especially for large-scale games.
- **Latency:** Players may experience higher latency if the server is geographically distant from them.
- **Single Point of Failure:** If the server goes down, all players are affected.
- **Complexity:** Setting up and maintaining a dedicated server can be complex and requires technical expertise.

## Listed Client-Server Model
<img src="Images/Listed-Client-Server-Model.png" alt="Listed Client-Server Model" width="300" height="auto"/>

The Listed Client-Server model is a variation of the client-server model where instead of a dedicated server there is a client(the host) that also runs the server.

#### pro's
- **Cost-Effective:** Because I client also runs the server there is no need for a dedicated server.
- **Consistency:** All clients receive updates from the same source, reducing the risk of desynchronization.
- **Security:** Since the server controls the game logic, it is harder for players to manipulate the game state.
- **Easier to Set Up:** There is no need to set up and maintain a dedicated server, making it easier for small-scale games or local multiplayer.

#### con's
- **Host Advantage:** The host may have a performance advantage since they are running both the client and server.
- **Security:** Since the host controls the game logic, it may be easier for the host to manipulate the game state.
- **Single point of failure:** If the host leaves or lose there connection, the server goes down and all players are disconnected.
- **Less scalable:** The host may not be able to handle many clients, making it less suitable for large-scale multiplayer games.

## Peer-to-Peer Model
<img src="Images/Peer-To-Peer.png" alt="Peer To Peer Model" width="300" height="auto"/>

The peer-to-peer (P2P) model is a network architecture without a dedicated server where all clients (peers) connect directly to each other and acts both as a client and server.

#### pro's
- **Cost-Effective:** There is no need for a dedicated server, making it more affordable for small-scale games.
- **Reduced Latency:** Players may experience lower latency since they connect directly to each other.
- **No single point of failure:** If one peer leaves or loses their connection, the game can continue as long as there are other peers connected.
- **Scalability:** The network can grow as more peers join, making it suitable for certain types of multiplayer games.

#### con's
- **Security Risks:** Without a central server, it is easier for players to manipulate the game state and cheat.
- **Consistency:** Harder to maintain a consistent game state across all players.
- **Network Complexity:** Managing connections between multiple peers can be complex and may lead to connectivity issues.
- **Bandwidth Usage:** Each peer must handle multiple connections, which can lead to increased bandwidth usage and potential performance issues.

### Hybrid Model
<img src="Images/Hybrid-Model.png" alt="Hybrid Model" width="300" height="auto"/>

The hybrid model combines the elements of both client-server and peer-to-peer architectures. 
In this model a central server manages the overall game state while allowing direct peer-to-peer communication for certain tasks.

#### pro's
- **Improved Performance:** By allowing direct peer-to-peer communication for certain action you can reduce latency and server load.
- **Scalability:** By offloading some tasks to peer-to-peer communication, the server can handle more clients.
- **Security:** By handling critical game logic on the server, it reduces the risk of cheating.

#### Con's
- **Complexity:** The hybrid model can be more complex to implement and manage due to the combination of both architectures.
- **Cost:** Even though the server load is reduced, there still needs to be a central server.


## conclusion
After researching the different network architectures and their pros and cons, I have chosen to implement the listed client-server model for my multiplayer system.
The reason for this decision is that because of the scope of the project and use case. 
The listed client-server model provides a good balance for small-scale multiplayer games with no need for a dedicated server, while still maintaining consistency and security.

## Sources
- https://www.getgud.io/blog/mastering-multiplayer-game-architecture-choosing-the-right-approach/
- https://hogonext.com/how-to-build-multiplayer-games-and-network-architectures/
- https://www.geeksforgeeks.org/system-design/client-server-model/
- https://www.geeksforgeeks.org/system-design/peer-to-peer-p2p-architecture/
- https://fish-networking.gitbook.io/docs/guides/high-level-overview/networking-models