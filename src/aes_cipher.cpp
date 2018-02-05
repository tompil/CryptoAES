#include <aes_cipher.h>


namespace aes {

    void aes_cipherer::cipher(const_block in, block out) const {
        using namespace internal;
        auto add_round_key = block_xor;

        std::copy(in.begin(), in.end(), out.begin());
        add_round_key(out, ekey_[0]);

        for (uint8_t i = 1; i < ekey_.size() - 1; ++i) {
            subbytes(out);
            shiftrows(out);
            mixcolumns(out);
            add_round_key(out, ekey_[i]);
        }

        subbytes(out);
        shiftrows(out);
        add_round_key(out, ekey_[ekey_.size() - 1]);
    }

}