
int RSA_verify(int type,uchar *m,uint m_length,uchar *sigbuf,uint siglen,RSA *rsa)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uchar *puVar4;
  int *piVar5;
  undefined4 uVar6;
  uchar *puVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  char *pcVar10;
  uchar *puVar11;
  _func_1627 *p_Var12;
  uchar *local_34;
  undefined4 local_30;
  undefined *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(undefined **)PTR___stack_chk_guard_006a9ae8;
  if (((rsa->flags & 0x40U) != 0) && (p_Var12 = rsa->meth->rsa_verify, p_Var12 != (_func_1627 *)0x0)
     ) {
    iVar2 = (*p_Var12)(type,m,m_length,sigbuf,siglen,rsa);
    goto LAB_0050ef3c;
  }
  uVar3 = RSA_size(rsa);
  if (siglen != uVar3) {
    m_length = (uint)&DAT_00000077;
    pcVar10 = "rsa_sign.c";
    m = (uchar *)0x91;
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x91,0x77,"rsa_sign.c",0xba);
    iVar2 = 0;
    sigbuf = (uchar *)pcVar10;
    goto LAB_0050ef3c;
  }
  puVar11 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(siglen,"rsa_sign.c",199);
  if (puVar11 == (uchar *)0x0) {
    pcVar10 = "rsa_sign.c";
    m_length = (uint)&DAT_00000041;
    m = (uchar *)0x91;
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x91,0x41,"rsa_sign.c",0xc9);
    iVar2 = 0;
    sigbuf = (uchar *)pcVar10;
    goto LAB_0050ef3c;
  }
  puVar7 = puVar11;
  if (type == 0x72) {
    if (m_length == 0x24) {
      iVar2 = RSA_public_decrypt(siglen,sigbuf,puVar11,rsa,1);
      pcVar10 = (char *)rsa;
      if (iVar2 < 1) goto LAB_0050f0bc;
      if (iVar2 == 0x24) {
        m_length = (uint)&DAT_00000024;
        iVar2 = (*(code *)PTR_memcmp_006a9ad0)(puVar11,m,0x24);
        if (iVar2 == 0) goto LAB_0050f150;
      }
      puVar7 = &DAT_00000068;
      uVar6 = 0xe5;
    }
    else {
      puVar7 = (uchar *)0x83;
      uVar6 = 0xcd;
    }
LAB_0050f0ac:
    pcVar10 = "rsa_sign.c";
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x91,puVar7,"rsa_sign.c",uVar6);
LAB_0050f0bc:
    m_length = (uint)puVar7;
    iVar2 = 0;
  }
  else {
    puVar4 = (uchar *)RSA_public_decrypt(siglen,sigbuf,puVar11,rsa,1);
    pcVar10 = (char *)rsa;
    if ((int)puVar4 < 1) goto LAB_0050f0bc;
    if ((((type == 0x5f) && (puVar4 == &DAT_00000012)) && (*puVar11 == '\x04')) &&
       (puVar11[1] == '\x10')) {
      m_length = (uint)&SUB_00000010;
      iVar2 = (*(code *)PTR_memcmp_006a9ad0)(m,puVar11 + 2,0x10);
      if (iVar2 != 0) {
        puVar7 = &DAT_00000068;
        uVar6 = 0xde;
        goto LAB_0050f0ac;
      }
LAB_0050f150:
      iVar2 = 1;
      pcVar10 = (char *)rsa;
    }
    else {
      puVar7 = puVar4;
      local_34 = puVar11;
      piVar5 = (int *)(*(code *)PTR_d2i_X509_SIG_006a8738)(0,&local_34,puVar4);
      pcVar10 = (char *)rsa;
      if (piVar5 == (int *)0x0) goto LAB_0050f0bc;
      if (local_34 == puVar11 + (int)puVar4) {
        local_30 = 0;
        puVar7 = (uchar *)(*(code *)PTR_i2d_X509_SIG_006a8734)(piVar5,&local_30);
        uVar6 = local_30;
        if ((int)puVar7 < 1) goto LAB_0050f024;
        if (puVar4 != puVar7) {
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_30,puVar7);
          (*(code *)PTR_CRYPTO_free_006a6e88)(local_30);
          goto LAB_0050f024;
        }
        iVar2 = (*(code *)PTR_memcmp_006a9ad0)(puVar11,local_30,puVar4);
        (*(code *)PTR_OPENSSL_cleanse_006a7074)(uVar6,puVar4);
        (*(code *)PTR_CRYPTO_free_006a6e88)(local_30);
        if (iVar2 != 0) goto LAB_0050f024;
        puVar8 = (undefined4 *)*piVar5;
        pcVar10 = (char *)rsa;
        if (puVar8[1] != 0) {
          iVar2 = (*(code *)PTR_ASN1_TYPE_get_006a74b0)();
          if (iVar2 == 5) {
            puVar8 = (undefined4 *)*piVar5;
            pcVar10 = (char *)rsa;
            goto LAB_0050f29c;
          }
          pcVar10 = "rsa_sign.c";
          m_length = (uint)&DAT_00000068;
          (*(code *)PTR_ERR_put_error_006a7f34)(4,0x91,0x68,"rsa_sign.c",0xfb);
          goto LAB_0050f048;
        }
LAB_0050f29c:
        iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar8);
        if (type != iVar2) {
          if (type == 4) {
            if (iVar2 == 8) goto LAB_0050f328;
          }
          else if ((type == 3) && (iVar2 == 7)) {
LAB_0050f328:
            pcVar10 = *(char **)PTR_stderr_006a9af8;
            (*(code *)PTR_fwrite_006a9a74)
                      ("signature has problems, re-make with post SSLeay045\n",1,0x34);
            goto LAB_0050f34c;
          }
          pcVar10 = "rsa_sign.c";
          m_length = (uint)&DAT_00000064;
          (*(code *)PTR_ERR_put_error_006a7f34)(4,0x91,100,"rsa_sign.c",0x111);
          goto LAB_0050f048;
        }
LAB_0050f34c:
        if ((m_length == *(uint *)piVar5[1]) &&
           (iVar2 = (*(code *)PTR_memcmp_006a9ad0)(m,((uint *)piVar5[1])[2],m_length), iVar2 == 0))
        {
          iVar2 = 1;
        }
        else {
          pcVar10 = "rsa_sign.c";
          m_length = (uint)&DAT_00000068;
          iVar2 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(4,0x91,0x68,"rsa_sign.c",0x121);
        }
      }
      else {
LAB_0050f024:
        pcVar10 = "rsa_sign.c";
        m_length = (uint)&DAT_00000068;
        (*(code *)PTR_ERR_put_error_006a7f34)(4,0x91,0x68,"rsa_sign.c",0xf1);
LAB_0050f048:
        iVar2 = 0;
      }
      (*(code *)PTR_X509_SIG_free_006a7ca8)(piVar5);
    }
  }
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(puVar11);
  (*(code *)PTR_CRYPTO_free_006a6e88)(puVar11);
  m = (uchar *)siglen;
  sigbuf = (uchar *)pcVar10;
LAB_0050ef3c:
  if (local_2c == *(undefined **)puVar1) {
    return iVar2;
  }
  puVar9 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR_memset_006a99f4;
  if ((int)(m + -10) <= (int)sigbuf) {
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x6c,0x6e,"rsa_pk1.c",0x4b);
    return 0;
  }
  *puVar9 = 0;
  puVar11 = m + (-3 - (int)sigbuf);
  puVar9[1] = 1;
  iVar2 = (*(code *)puVar1)(puVar9 + 2,0xff,puVar11);
  puVar11[iVar2] = '\0';
  (*(code *)PTR_memcpy_006a9aec)(puVar11 + iVar2 + 1,m_length,sigbuf);
  return 1;
}

