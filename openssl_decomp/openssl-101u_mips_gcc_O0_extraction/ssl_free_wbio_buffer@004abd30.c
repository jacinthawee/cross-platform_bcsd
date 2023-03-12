
void ssl_free_wbio_buffer(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  if (iVar2 != 0) {
    if (iVar2 == *(int *)(param_1 + 0x10)) {
      uVar1 = (*(code *)PTR_BIO_pop_006a79c8)(iVar2);
      iVar2 = *(int *)(param_1 + 0x14);
      *(undefined4 *)(param_1 + 0x10) = uVar1;
    }
    (*(code *)PTR_BIO_free_006a6e70)(iVar2);
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}

