
int by_dir_hash_cmp(uint **param_1,uint **param_2)

{
  if (**param_1 <= **param_2) {
    return -(uint)(**param_1 < **param_2);
  }
  return 1;
}

