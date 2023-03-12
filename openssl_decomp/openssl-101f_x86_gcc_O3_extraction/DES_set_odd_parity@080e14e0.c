
void DES_set_odd_parity(DES_cblock *key)

{
  (*key)[0] = odd_parity[(*key)[0]];
  (*key)[1] = odd_parity[(*key)[1]];
  (*key)[2] = odd_parity[(*key)[2]];
  (*key)[3] = odd_parity[(*key)[3]];
  (*key)[4] = odd_parity[(*key)[4]];
  (*key)[5] = odd_parity[(*key)[5]];
  (*key)[6] = odd_parity[(*key)[6]];
  (*key)[7] = odd_parity[(*key)[7]];
  return;
}

