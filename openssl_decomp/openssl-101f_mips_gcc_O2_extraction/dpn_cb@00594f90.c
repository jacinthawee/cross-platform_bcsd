
undefined4 dpn_cb(int param_1,int *param_2)

{
  if (param_1 == 1) {
    *(undefined4 *)(*param_2 + 8) = 0;
  }
  else if ((param_1 == 3) && (*(int *)(*param_2 + 8) != 0)) {
    (*(code *)PTR_X509_NAME_free_006a80f8)();
    return 1;
  }
  return 1;
}

