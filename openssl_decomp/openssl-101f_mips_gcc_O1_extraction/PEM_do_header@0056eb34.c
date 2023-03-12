
int PEM_do_header(EVP_CIPHER_INFO *cipher,uchar *data,long *len,undefined1 *callback,void *u)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  EVP_CIPHER *pEVar9;
  char *pcVar10;
  byte *pbVar11;
  uint uVar12;
  int iVar13;
  undefined4 uVar14;
  char *pcVar15;
  long lVar16;
  int local_500;
  long local_4fc;
  undefined auStack_4f8 [140];
  undefined auStack_46c [64];
  char acStack_42c [1024];
  char *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(char **)PTR___stack_chk_guard_006aabf0;
  lVar16 = *len;
  if (cipher->cipher == (EVP_CIPHER *)0x0) {
    iVar3 = 1;
    piVar4 = (int *)data;
  }
  else {
    if (callback == (undefined1 *)0x0) {
      iVar3 = PEM_def_callback(acStack_42c,0x400,0,u);
    }
    else {
      iVar3 = (*(code *)callback)();
    }
    if (iVar3 < 1) {
      piVar4 = (int *)&DAT_0000006a;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x6a,0x68,"pem_lib.c",0x1ca);
      iVar3 = 0;
    }
    else {
      pEVar9 = cipher->cipher;
      piVar4 = (int *)(*(code *)PTR_EVP_md5_006a81c8)();
      iVar3 = (*(code *)PTR_EVP_BytesToKey_006a8644)
                        (pEVar9,piVar4,cipher->iv,acStack_42c,iVar3,1,auStack_46c,0);
      if (iVar3 != 0) {
        local_4fc = lVar16;
        (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(auStack_4f8);
        iVar3 = (*(code *)PTR_EVP_DecryptInit_ex_006a8b54)
                          (auStack_4f8,cipher->cipher,0,auStack_46c,cipher->iv);
        if ((iVar3 == 0) ||
           (iVar3 = (*(code *)PTR_EVP_DecryptUpdate_006a8b5c)
                              (auStack_4f8,data,&local_500,data,local_4fc), iVar3 == 0)) {
          (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_4f8);
          (*(code *)PTR_OPENSSL_cleanse_006a8174)(acStack_42c,0x400);
          (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_46c,0x40);
          local_4fc = local_4fc + local_500;
        }
        else {
          iVar3 = (*(code *)PTR_EVP_DecryptFinal_ex_006a8b58)
                            (auStack_4f8,data + local_500,&local_4fc);
          (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_4f8);
          (*(code *)PTR_OPENSSL_cleanse_006a8174)(acStack_42c,0x400);
          piVar4 = (int *)&DAT_00000040;
          (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_46c);
          local_4fc = local_4fc + local_500;
          if (iVar3 != 0) {
            *len = local_4fc;
            iVar3 = 1;
            goto LAB_0056ec14;
          }
        }
        piVar4 = (int *)&DAT_0000006a;
        (*(code *)PTR_ERR_put_error_006a9030)(9,0x6a,0x65,"pem_lib.c",0x1e3);
        iVar3 = 0;
      }
    }
  }
LAB_0056ec14:
  if (local_2c == *(char **)puVar2) {
    return iVar3;
  }
  pcVar10 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  *piVar4 = 0;
  if (((pcVar10 == (char *)0x0) || (*pcVar10 == '\0')) || (*pcVar10 == '\n')) {
LAB_0056ef40:
    iVar3 = 1;
  }
  else {
    iVar3 = (*(code *)PTR_strncmp_006aaa7c)();
    if (iVar3 != 0) {
      uVar14 = 0x6b;
      uVar8 = 500;
LAB_0056ef78:
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x6b,uVar14,"pem_lib.c",uVar8);
      return 0;
    }
    if (pcVar10[0xb] != '4') {
      return 0;
    }
    if (pcVar10[0xc] != ',') {
      return 0;
    }
    pcVar15 = pcVar10 + 0xd;
    iVar5 = (*(code *)PTR_strncmp_006aaa7c)(pcVar15,"ENCRYPTED",9);
    if (iVar5 == 0) {
      cVar1 = pcVar10[0xd];
      while (cVar1 != '\n') {
        if (cVar1 == '\0') {
          uVar14 = 0x70;
          uVar8 = 0x1fd;
          goto LAB_0056ef78;
        }
        pcVar15 = pcVar15 + 1;
        cVar1 = *pcVar15;
      }
      iVar3 = (*(code *)PTR_strncmp_006aaa7c)(pcVar15 + 1,"DEK-Info: ",10);
      puVar2 = PTR_EVP_get_cipherbyname_006a8494;
      if (iVar3 != 0) {
        uVar14 = 0x69;
        uVar8 = 0x200;
        goto LAB_0056ef78;
      }
      pcVar15 = pcVar15 + 0xb;
      while( true ) {
        cVar1 = *pcVar15;
        uVar6 = (int)cVar1 & 0xff;
        if (((0x19 < uVar6 - 0x41) && ((int)cVar1 != 0x2d)) && (9 < uVar6 - 0x30)) break;
        pcVar15 = pcVar15 + 1;
      }
      *pcVar15 = '\0';
      iVar5 = (*(code *)puVar2)();
      *piVar4 = iVar5;
      *pcVar15 = cVar1;
      if (iVar5 != 0) {
        iVar3 = *(int *)(iVar5 + 0xc);
        if (0 < iVar3) {
          (*(code *)PTR_memset_006aab00)(piVar4 + 1,0,iVar3);
        }
        uVar6 = 0;
        if (0 < iVar3 << 1) {
          do {
            pcVar15 = pcVar15 + 1;
            uVar7 = (uint)*pcVar15;
            uVar12 = uVar7 & 0xff;
            if (uVar12 - 0x30 < 10) {
              iVar5 = uVar7 - 0x30;
            }
            else if (uVar12 - 0x41 < 6) {
              iVar5 = uVar7 - 0x37;
            }
            else {
              iVar5 = uVar7 - 0x57;
              if (5 < uVar12 - 0x61) {
                (*(code *)PTR_ERR_put_error_006a9030)(9,0x65,0x67,"pem_lib.c",0x234);
                return 0;
              }
            }
            iVar13 = 4;
            if ((uVar6 & 1) != 0) {
              iVar13 = 0;
            }
            pbVar11 = (byte *)((int)(piVar4 + 1) + ((int)uVar6 >> 1));
            uVar6 = uVar6 + 1;
            *pbVar11 = *pbVar11 | (byte)(iVar5 << iVar13);
          } while (iVar3 << 1 != uVar6);
        }
        goto LAB_0056ef40;
      }
      uVar14 = 0x72;
      uVar8 = 0x219;
    }
    else {
      uVar14 = 0x6a;
      uVar8 = 0x1f9;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x6b,uVar14,"pem_lib.c",uVar8);
  }
  return iVar3;
}

