 # File - Logistic-Extract.cpp
 
 # Brief Scholastic Demonstration of Static Binary Analysis & Heuristic Mapping
 * 
 * THEORY: Embedded systems interact with hardware via Memory-Mapped I/O (MMIO).
 * This program implements a 'Signature-Based Heuristic' to reconstruct high-level 
 * logic from raw binary blobs by identifying known peripheral base addresses.
 */
 # Logistic-Extract
Embedded systems interact with hardware via Memory-Mapped I/O (MMIO).  * This program implements a 'Signature-Based Heuristic' to reconstruct high-level extracted logic from raw binary blobs by identifying known peripheral base addresses.

                              Computational Briefing.
                              
1. SYNTAX: reinterpret_cast<const uint32_t*>
   - ROLE: Type Punning.
   - BRIEF: Instructs the compiler to treat a sequence of raw bytes (uint8_t) 
     as a different data type (uint32_t) without changing the underlying bits.
     Used here to reconstruct 32-bit CPU addresses from an 8-bit stream.

2. SYNTAX: std::map::count(key)
   - ROLE: Membership Verification.
   - BRIEF: Returns 1 if the key exists, 0 otherwise. In this context, it 
     performs a O(log n) search to see if a binary "word" is a known hardware 
     address stored in our architecture profile.

3. COMPUTATION: Linear Sweep Analysis
   - LOGIC: i + 3 < firmware.size(); i += 4
   - BRIEF: Iterates through the binary file in 4-byte increments. This mimics 
     how a 32-bit CPU fetches instructions, ensuring we only analyze 
     "word-aligned" data blocks.

4. COMPUTATION: MMIO (Memory-Mapped I/O) Heuristics
   - LOGIC: Mapping hex addresses to code strings.
   - BRIEF: Embedded hardware does not have "names" inside the machine code. 
     Instead, it uses specific memory addresses to control pins or sensors. 
     By spotting these addresses (e.g., 0x40012400), we can "guess" that the 
     code is intended to read an Analog-to-Digital converter.

5. DATA STRUCTURE: std::vector<uint8_t>
   - ROLE: Dynamic Buffer.
   - BRIEF: A contiguous memory array used to store the binary firmware blob. 
     Using 'uint8_t' ensures that we handle data at the finest granularity (bytes).
