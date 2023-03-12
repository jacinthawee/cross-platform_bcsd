
char * set_pbe_isra_0(char **param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 != (char *)0x0) {
    iVar1 = strcmp(param_2,"NONE");
    if (iVar1 == 0) {
      *param_1 = (char *)0xffffffff;
      param_2 = (char *)0x1;
    }
    else {
      pcVar2 = (char *)OBJ_txt2nid(param_2);
      *param_1 = pcVar2;
      if (pcVar2 == (char *)0x0) {
        BIO_printf(bio_err,"Unknown PBE algorithm %s\n",param_2);
        param_2 = pcVar2;
      }
      else {
        param_2 = (char *)0x1;
      }
    }
  }
  return param_2;
}

