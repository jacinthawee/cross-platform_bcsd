
undefined4 ri_cb(int param_1,int *param_2)

{
  if (param_1 != 3) {
    return 1;
  }
  (*(code *)PTR_X509_free_006a7f90)(*(undefined4 *)(*param_2 + 0x10));
  return 1;
}

