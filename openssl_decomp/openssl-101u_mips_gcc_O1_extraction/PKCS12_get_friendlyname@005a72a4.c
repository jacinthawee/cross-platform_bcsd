
char * PKCS12_get_friendlyname(PKCS12_SAFEBAG *bag)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  stack_st_X509_ATTRIBUTE *psVar6;
  
  psVar6 = bag->attrib;
  iVar5 = 0;
  if (psVar6 != (stack_st_X509_ATTRIBUTE *)0x0) {
    do {
      iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psVar6);
      if (iVar2 <= iVar5) {
        return (char *)0x0;
      }
      puVar1 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(psVar6,iVar5);
      iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar1);
      iVar5 = iVar5 + 1;
    } while (iVar2 != 0x9c);
    iVar5 = (*(code *)PTR_sk_num_006a6e2c)(puVar1[2]);
    if (((iVar5 != 0) &&
        (piVar3 = (int *)(*(code *)PTR_sk_value_006a6e24)(puVar1[2],0), piVar3 != (int *)0x0)) &&
       (*piVar3 == 0x1e)) {
      pcVar4 = OPENSSL_uni2asc((uchar *)((int *)piVar3[1])[2],*(int *)piVar3[1]);
      return pcVar4;
    }
  }
  return (char *)0x0;
}

