
ENGINE * ENGINE_by_id(char *id)

{
  char **ppcVar1;
  int iVar2;
  char *pcVar3;
  ENGINE *e;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char **ppcVar8;
  char *pcVar9;
  char *pcVar10;
  
  if (id == (char *)0x0) {
    ERR_put_error(0x26,0x6a,0x43,"eng_list.c",0x14a);
    return (ENGINE *)0x0;
  }
  CRYPTO_lock(9,0x1e,"eng_list.c",0x14d);
  for (ppcVar8 = engine_list_head; ppcVar8 != (char **)0x0; ppcVar8 = (char **)ppcVar8[0x1b]) {
    iVar2 = strcmp(id,*ppcVar8);
    if (iVar2 == 0) {
      if ((int)ppcVar8[0x15] << 0x1d < 0) {
        ppcVar1 = (char **)ENGINE_new();
        if (ppcVar1 == (char **)0x0) break;
        pcVar10 = ppcVar8[1];
        pcVar9 = ppcVar8[2];
        ppcVar1[3] = ppcVar8[3];
        pcVar4 = ppcVar8[5];
        pcVar5 = ppcVar8[6];
        pcVar7 = ppcVar8[4];
        ppcVar1[7] = ppcVar8[7];
        pcVar3 = ppcVar8[8];
        ppcVar1[9] = ppcVar8[9];
        ppcVar1[10] = ppcVar8[10];
        ppcVar1[0xb] = ppcVar8[0xb];
        ppcVar1[0xd] = ppcVar8[0xd];
        *ppcVar1 = *ppcVar8;
        pcVar6 = ppcVar8[0xe];
        ppcVar1[1] = pcVar10;
        pcVar10 = ppcVar8[0xf];
        ppcVar1[0xe] = pcVar6;
        ppcVar1[2] = pcVar9;
        pcVar6 = ppcVar8[0x11];
        pcVar9 = ppcVar8[0x10];
        ppcVar1[5] = pcVar4;
        ppcVar1[0x11] = pcVar6;
        ppcVar1[6] = pcVar5;
        ppcVar1[4] = pcVar7;
        ppcVar1[8] = pcVar3;
        ppcVar1[0xf] = pcVar10;
        ppcVar1[0x10] = pcVar9;
        pcVar3 = ppcVar8[0x14];
        pcVar4 = ppcVar8[0x15];
        ppcVar1[0x12] = ppcVar8[0x12];
        ppcVar1[0x14] = pcVar3;
        ppcVar1[0x15] = pcVar4;
      }
      else {
        ppcVar8[0x16] = ppcVar8[0x16] + 1;
        ppcVar1 = ppcVar8;
      }
      CRYPTO_lock(10,0x1e,"eng_list.c",0x164);
      return (ENGINE *)ppcVar1;
    }
  }
  CRYPTO_lock(10,0x1e,"eng_list.c",0x164);
  iVar2 = strcmp(id,"dynamic");
  if (iVar2 != 0) {
    pcVar3 = getenv("OPENSSL_ENGINES");
    if (pcVar3 == (char *)0x0) {
      pcVar3 = "/usr/local/openssl101uo0/lib/engines";
    }
    e = ENGINE_by_id("dynamic");
    if (e != (ENGINE *)0x0) {
      iVar2 = ENGINE_ctrl_cmd_string(e,"ID",id,0);
      if ((((iVar2 != 0) && (iVar2 = ENGINE_ctrl_cmd_string(e,"DIR_LOAD","2",0), iVar2 != 0)) &&
          (iVar2 = ENGINE_ctrl_cmd_string(e,"DIR_ADD",pcVar3,0), iVar2 != 0)) &&
         ((iVar2 = ENGINE_ctrl_cmd_string(e,"LIST_ADD","1",0), iVar2 != 0 &&
          (iVar2 = ENGINE_ctrl_cmd_string(e,"LOAD",(char *)0x0,0), iVar2 != 0)))) {
        return e;
      }
      goto LAB_0009a5fe;
    }
  }
  e = (ENGINE *)0x0;
LAB_0009a5fe:
  ENGINE_free(e);
  ERR_put_error(0x26,0x6a,0x74,"eng_list.c",0x186);
  ERR_add_error_data(2,&DAT_0015d7b8,id);
  return (ENGINE *)0x0;
}

