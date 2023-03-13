
ENGINE * __regparm1 ENGINE_by_id(char *id)

{
  char *arg;
  ENGINE *e;
  int iVar1;
  char **ppcVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined uVar5;
  undefined uVar6;
  byte bVar7;
  byte *in_stack_00000004;
  
  bVar7 = 0;
  if (in_stack_00000004 == (byte *)0x0) {
    ERR_put_error(0x26,0x6a,0x43,"eng_list.c",0x14a);
    return (ENGINE *)0x0;
  }
  CRYPTO_lock((int)id,9,(char *)0x1e,(int)"eng_list.c");
  for (ppcVar2 = engine_list_head; uVar6 = ppcVar2 == (char **)0x0, !(bool)uVar6;
      ppcVar2 = (char **)ppcVar2[0x1b]) {
    id = (char *)strcmp((char *)in_stack_00000004,*ppcVar2);
    if ((char **)id == (char **)0x0) {
      if ((*(byte *)(ppcVar2 + 0x15) & 4) == 0) {
        ppcVar2[0x16] = ppcVar2[0x16] + 1;
      }
      else {
        id = (char *)ENGINE_new();
        uVar6 = (char **)id == (char **)0x0;
        if ((bool)uVar6) break;
        *(char **)id = *ppcVar2;
        *(char **)((int)id + 4) = ppcVar2[1];
        *(char **)((int)id + 8) = ppcVar2[2];
        *(char **)((int)id + 0xc) = ppcVar2[3];
        *(char **)((int)id + 0x10) = ppcVar2[4];
        *(char **)((int)id + 0x14) = ppcVar2[5];
        *(char **)((int)id + 0x18) = ppcVar2[6];
        *(char **)((int)id + 0x1c) = ppcVar2[7];
        *(char **)((int)id + 0x20) = ppcVar2[8];
        *(char **)((int)id + 0x24) = ppcVar2[9];
        *(char **)((int)id + 0x28) = ppcVar2[10];
        *(char **)((int)id + 0x2c) = ppcVar2[0xb];
        *(char **)((int)id + 0x34) = ppcVar2[0xd];
        *(char **)((int)id + 0x38) = ppcVar2[0xe];
        *(char **)((int)id + 0x3c) = ppcVar2[0xf];
        *(char **)((int)id + 0x40) = ppcVar2[0x10];
        *(char **)((int)id + 0x44) = ppcVar2[0x11];
        *(char **)((int)id + 0x48) = ppcVar2[0x12];
        *(char **)((int)id + 0x50) = ppcVar2[0x14];
        *(char **)((int)id + 0x54) = ppcVar2[0x15];
        ppcVar2 = (char **)id;
      }
      CRYPTO_lock((int)id,10,(char *)0x1e,(int)"eng_list.c");
      return (ENGINE *)ppcVar2;
    }
  }
  uVar5 = 0;
  CRYPTO_lock((int)id,10,(char *)0x1e,(int)"eng_list.c");
  iVar1 = 8;
  pbVar3 = in_stack_00000004;
  pbVar4 = (byte *)"dynamic";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    uVar5 = *pbVar3 < *pbVar4;
    uVar6 = *pbVar3 == *pbVar4;
    pbVar3 = pbVar3 + (uint)bVar7 * -2 + 1;
    pbVar4 = pbVar4 + (uint)bVar7 * -2 + 1;
  } while ((bool)uVar6);
  if ((!(bool)uVar5 && !(bool)uVar6) != (bool)uVar5) {
    arg = getenv("OPENSSL_ENGINES");
    if (arg == (char *)0x0) {
      arg = "/usr/local/openssl101ux86o1/lib/engines";
    }
    e = ENGINE_by_id("/usr/local/openssl101ux86o1/lib/engines");
    if (e != (ENGINE *)0x0) {
      iVar1 = ENGINE_ctrl_cmd_string(e,"ID",(char *)in_stack_00000004,0);
      if ((((iVar1 != 0) && (iVar1 = ENGINE_ctrl_cmd_string(e,"DIR_LOAD","2",0), iVar1 != 0)) &&
          (iVar1 = ENGINE_ctrl_cmd_string(e,"DIR_ADD",arg,0), iVar1 != 0)) &&
         ((iVar1 = ENGINE_ctrl_cmd_string(e,"LIST_ADD","1",0), iVar1 != 0 &&
          (iVar1 = ENGINE_ctrl_cmd_string(e,"LOAD",(char *)0x0,0), iVar1 != 0)))) {
        return e;
      }
      goto LAB_08111abe;
    }
  }
  e = (ENGINE *)0x0;
LAB_08111abe:
  ENGINE_free(e);
  ERR_put_error(0x26,0x6a,0x74,"eng_list.c",0x186);
  ERR_add_error_data(2,&DAT_08223242);
  return (ENGINE *)0x0;
}

