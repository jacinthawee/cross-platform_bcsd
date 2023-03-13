
int __regparm3 set_pbe_isra_0(int *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 != (char *)0x0) {
    iVar1 = strcmp(param_2,"NONE");
    if (iVar1 == 0) {
      *param_1 = -1;
      iVar1 = 1;
    }
    else {
      iVar1 = OBJ_txt2nid(param_2);
      *param_1 = iVar1;
      if (iVar1 == 0) {
        BIO_printf(bio_err,"Unknown PBE algorithm %s\n",param_2,0);
      }
      else {
        iVar1 = 1;
      }
    }
  }
  return iVar1;
}

