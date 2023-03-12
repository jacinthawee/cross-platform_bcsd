
ENGINE * ENGINE_by_id(char *id)

{
  undefined4 *puVar1;
  int iVar2;
  char *arg;
  ENGINE *e;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  
  if (id == (char *)0x0) {
    ERR_put_error(0x26,0x6a,0x43,"eng_list.c",0x14a);
    return (ENGINE *)0x0;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_list.c",0x14d);
  for (puVar15 = engine_list_head; puVar15 != (undefined4 *)0x0;
      puVar15 = (undefined4 *)puVar15[0x1b]) {
    iVar2 = (*(code *)PTR_strcmp_006a9b18)(id,*puVar15);
    if (iVar2 == 0) {
      if ((puVar15[0x15] & 4) == 0) {
        puVar15[0x16] = puVar15[0x16] + 1;
        puVar1 = puVar15;
      }
      else {
        puVar1 = (undefined4 *)ENGINE_new();
        if (puVar1 == (undefined4 *)0x0) break;
        uVar4 = puVar15[0xf];
        uVar3 = puVar15[0x10];
        uVar16 = *puVar15;
        uVar18 = puVar15[1];
        uVar17 = puVar15[2];
        uVar14 = puVar15[3];
        uVar13 = puVar15[4];
        uVar12 = puVar15[5];
        uVar11 = puVar15[6];
        uVar10 = puVar15[7];
        uVar9 = puVar15[8];
        uVar8 = puVar15[9];
        uVar7 = puVar15[10];
        uVar6 = puVar15[0xb];
        uVar5 = puVar15[0xd];
        puVar1[0xe] = puVar15[0xe];
        puVar1[0xf] = uVar4;
        puVar1[0x10] = uVar3;
        *puVar1 = uVar16;
        puVar1[1] = uVar18;
        puVar1[2] = uVar17;
        puVar1[3] = uVar14;
        puVar1[4] = uVar13;
        puVar1[5] = uVar12;
        puVar1[6] = uVar11;
        puVar1[7] = uVar10;
        puVar1[8] = uVar9;
        puVar1[9] = uVar8;
        puVar1[10] = uVar7;
        puVar1[0xb] = uVar6;
        puVar1[0xd] = uVar5;
        uVar5 = puVar15[0x12];
        uVar4 = puVar15[0x14];
        uVar3 = puVar15[0x15];
        puVar1[0x11] = puVar15[0x11];
        puVar1[0x12] = uVar5;
        puVar1[0x14] = uVar4;
        puVar1[0x15] = uVar3;
      }
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_list.c",0x164);
      return (ENGINE *)puVar1;
    }
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_list.c",0x164);
  iVar2 = (*(code *)PTR_strcmp_006a9b18)(id,"dynamic");
  if (iVar2 != 0) {
    arg = (char *)(*(code *)PTR_getenv_006a9a60)("OPENSSL_ENGINES");
    if (arg == (char *)0x0) {
      arg = "/usr/local/openssl101umipso1/lib/engines";
    }
    e = ENGINE_by_id("dynamic");
    if (e != (ENGINE *)0x0) {
      iVar2 = ENGINE_ctrl_cmd_string(e,"ID",id,0);
      if ((((iVar2 != 0) && (iVar2 = ENGINE_ctrl_cmd_string(e,"DIR_LOAD","2",0), iVar2 != 0)) &&
          (iVar2 = ENGINE_ctrl_cmd_string(e,"DIR_ADD",arg,0), iVar2 != 0)) &&
         ((iVar2 = ENGINE_ctrl_cmd_string(e,"LIST_ADD","1",0), iVar2 != 0 &&
          (iVar2 = ENGINE_ctrl_cmd_string(e,"LOAD",(char *)0x0,0), iVar2 != 0)))) {
        return e;
      }
      goto LAB_00519034;
    }
  }
  e = (ENGINE *)0x0;
LAB_00519034:
  ENGINE_free(e);
  ERR_put_error(0x26,0x6a,0x74,"eng_list.c",0x186);
  ERR_add_error_data(2,&DAT_0066706c,id);
  return (ENGINE *)0x0;
}

