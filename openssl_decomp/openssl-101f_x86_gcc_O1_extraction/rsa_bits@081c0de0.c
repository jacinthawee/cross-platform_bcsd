
void rsa_bits(int param_1)

{
  BN_num_bits(*(BIGNUM **)(*(int *)(param_1 + 0x14) + 0x10));
  return;
}
