/* --- DATA ABSTRACTION LAYER --- 

 * We define a schema to map physical hardware addresses (hexadecimal) 
 
 * to human-readable intent (string metadata).
 
 */

struct Peripheral {
    std::string name;          // Hardware Register Name (e.g., GPIOA)

    std::string purpose;       // Functional Role (e.g., Digital Output)

    std::string code_snippet;  // C-Code Reconstruction Template
};

struct ArchProfile {
    std::string name;          // ISA (Instruction Set Architecture) Identifier

    std::map<uint32_t, Peripheral> reg_map; // The "Dictionary" of address-to-logic
};
