
int DH_size(DH *dh)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)(dh->p);
  iVar2 = iVar1 + 7;
  if (iVar1 + 7 < 0) {
    iVar2 = iVar1 + 0xe;
  }
  return iVar2 >> 3;
}

