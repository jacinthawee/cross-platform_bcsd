
int mime_param_cmp(int **param_1,int **param_2)

{
  int iVar1;
  
  if ((**param_1 != 0) && (**param_2 != 0)) {
    iVar1 = (*(code *)PTR_strcmp_006a9b18)();
    return iVar1;
  }
  return (uint)(**param_1 != 0) - (uint)(**param_2 != 0);
}

