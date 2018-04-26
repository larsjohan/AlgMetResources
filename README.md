# AlgMetResources
Ressurser til pensum i algoritmiske metoder:
Eksemplene her er basert på koden i boken "Algorithms in C++" av Robert Sedgewick, 20 utg. (2004)

# Installasjon
1. Installer (Microsoft Visual Studio 2017 Community Edition)[https://www.visualstudio.com/vs/community/]
2. Installer (Git Bash)[https://git-scm.com/downloads]
3. Start Git Bash og naviger til mappen *over* den du vil lagre koden i.
4. Lag en kopi av repositoriet ved å kjøre denne kommandoen: *git clone https://github.com/larsjohan/AlgMetResources.git*
5. Start Visual Studio 2017
6. Klikk *File -> Open -> Project/Solution*
7. Naviger til mappen *AlgMetResources* Som ble opprettet i trinn 4.
8. Velg *AlgMetResources.sln* og klikk *Åpne*
9. I Vinduet *Solution Explorer* Skal det nå ligge 10 prosjekter:
  - DataStructures
  - FileCompression
  - Graphs
  - Hashing
  - NetworkFlow
  - PriorityQueues
  - Recursion
  - Search
  - Sorting
  - Trees
10. Høyreklikk på hvert prosjekt og velg *Properties*
11. Gå til *Configuration Properties -> C/C++ -> Precompiled Headers* i listen til venstre
12. Under *Precompiled Header* Velg *Not Using Precompiled Headers* i listen ok klikk bruk. 
13. Gjenta trinn 10 - 12 for alle prosjektene
14. Høyreklikk på *Solution 'AlgMetResources'(10 projects)* (Øverst i Solution Explorer) og velg *Rebuild Solution*.
15. Du skal nå få opp meldingen: *========== Rebuild All: 10 succeeded, 0 failed, 0 skipped ==========* i output-vinduet
16. Ferdig!
