
undefined4 si_cb(int param_1,int *param_2)

{
  if (param_1 != 3) {
    return 1;
  }
  (*(code *)PTR_EVP_PKEY_free_006a7f78)(*(undefined4 *)(*param_2 + 0x1c));
  return 1;
}

