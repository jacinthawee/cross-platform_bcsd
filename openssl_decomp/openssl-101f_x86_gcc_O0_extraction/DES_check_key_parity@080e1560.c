
int DES_check_key_parity(const_DES_cblock *key)

{
  if ((((odd_parity[(*key)[0]] == (*key)[0]) && ((*key)[1] == odd_parity[(*key)[1]])) &&
      ((*key)[2] == odd_parity[(*key)[2]])) &&
     ((((*key)[3] == odd_parity[(*key)[3]] && ((*key)[4] == odd_parity[(*key)[4]])) &&
      (((*key)[5] == odd_parity[(*key)[5]] && ((*key)[6] == odd_parity[(*key)[6]])))))) {
    return (uint)(odd_parity[(*key)[7]] == (*key)[7]);
  }
  return 0;
}

