
int dtls1_output_cert_chain(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  short sVar9;
  uint uVar7;
  BIO *pBVar8;
  SSL *ssl;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined *local_b8;
  undefined *local_b4 [21];
  undefined4 local_60;
  SSL *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iVar12 = *(int *)(param_1 + 0x3c);
  local_2c = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  iVar3 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(iVar12,10);
  if (iVar3 == 0) {
    iVar12 = 0xff;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xff,7,"d1_both.c",0x479);
    iVar3 = 0;
  }
  else {
    if (param_2 == 0) {
      iVar3 = 0xf;
    }
    else {
      iVar3 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)
                        (local_b4,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0xc),param_2,0);
      if (iVar3 == 0) {
        iVar12 = 0xff;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xff,0xb,"d1_both.c",0x480);
LAB_004a3cb4:
        iVar3 = 0;
        goto LAB_004a3cb8;
      }
      iVar11 = 0;
      (*(code *)PTR_X509_verify_cert_006a728c)(local_b4);
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
      iVar3 = 0xf;
      while( true ) {
        iVar4 = (*(code *)PTR_sk_num_006a6e2c)(local_60);
        if (iVar4 <= iVar11) break;
        uVar5 = (*(code *)PTR_sk_value_006a6e24)(local_60,iVar11);
        iVar4 = (*(code *)PTR_i2d_X509_006a76e8)(uVar5,0);
        iVar10 = iVar4 + 3 + iVar3;
        iVar6 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(iVar12,iVar10);
        puVar1 = PTR_i2d_X509_006a76e8;
        if (iVar6 == 0) {
          iVar12 = 0x127;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x127,7,"d1_both.c",0x464);
          (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(local_b4);
          goto LAB_004a3cb4;
        }
        local_b8 = (undefined *)(*(int *)(iVar12 + 4) + iVar3);
        iVar11 = iVar11 + 1;
        *local_b8 = (char)((uint)iVar4 >> 0x10);
        local_b8[1] = (char)((uint)iVar4 >> 8);
        local_b8[2] = (char)iVar4;
        local_b8 = local_b8 + 3;
        (*(code *)puVar1)(uVar5,&local_b8);
        iVar3 = iVar10;
      }
      (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(local_b4);
    }
    iVar11 = 0;
    while( true ) {
      iVar4 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x94));
      if (iVar4 <= iVar11) break;
      uVar5 = (*(code *)PTR_sk_value_006a6e24)
                        (*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x94),iVar11);
      iVar4 = (*(code *)PTR_i2d_X509_006a76e8)(uVar5,0);
      iVar10 = iVar4 + 3 + iVar3;
      iVar6 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(iVar12,iVar10);
      puVar1 = PTR_i2d_X509_006a76e8;
      if (iVar6 == 0) {
        iVar12 = 0x127;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x127,7,"d1_both.c",0x464);
        goto LAB_004a3cb4;
      }
      local_b4[0] = (undefined *)(*(int *)(iVar12 + 4) + iVar3);
      iVar11 = iVar11 + 1;
      *local_b4[0] = (char)((uint)iVar4 >> 0x10);
      local_b4[0][1] = (char)((uint)iVar4 >> 8);
      local_b4[0][2] = (char)iVar4;
      local_b4[0] = local_b4[0] + 3;
      (*(code *)puVar1)(uVar5,local_b4);
      iVar3 = iVar10;
    }
    iVar11 = iVar3 + -0xf;
    iVar12 = *(int *)(iVar12 + 4);
    *(char *)(iVar12 + 0xe) = (char)iVar11;
    *(char *)(iVar12 + 0xc) = (char)((uint)iVar11 >> 0x10);
    *(char *)(iVar12 + 0xd) = (char)((uint)iVar11 >> 8);
    iVar11 = *(int *)(param_1 + 0x5c);
    if (*(int *)(iVar11 + 0x254) == 0) {
      sVar9 = *(short *)(iVar11 + 0x226);
      *(short *)(iVar11 + 0x224) = sVar9;
      *(short *)(iVar11 + 0x226) = sVar9 + 1;
    }
    else {
      sVar9 = *(short *)(iVar11 + 0x224);
    }
    iVar12 = 0xb;
    *(short *)(iVar11 + 0x268) = sVar9;
    *(int *)(iVar11 + 0x264) = iVar3 + -0xc;
    *(undefined4 *)(iVar11 + 0x26c) = 0;
    *(undefined *)(iVar11 + 0x260) = 0xb;
    *(int *)(iVar11 + 0x270) = iVar3 + -0xc;
  }
LAB_004a3cb8:
  if (local_2c == *(SSL **)puVar2) {
    return iVar3;
  }
  ssl = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (iVar12 < 1) {
    iVar3 = dtls1_is_timer_expired();
    if (iVar3 == 0) {
      return iVar12;
    }
    uVar7 = SSL_state(ssl);
    if (((uVar7 & 0x3000) != 0) || (ssl->tlsext_heartbeat != 0)) {
      iVar3 = dtls1_handle_timeout(ssl);
      return iVar3;
    }
    pBVar8 = SSL_get_rbio(ssl);
    (*(code *)PTR_BIO_set_flags_006a7570)(pBVar8,1);
  }
  else {
    (*(code *)PTR___fprintf_chk_006a9980)
              (*(undefined4 *)PTR_stderr_006a9af8,1,"invalid state reached %s:%d","d1_both.c",0x4a7)
    ;
    iVar12 = 1;
  }
  return iVar12;
}

