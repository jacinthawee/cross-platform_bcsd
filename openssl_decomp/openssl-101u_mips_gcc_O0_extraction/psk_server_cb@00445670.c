
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int psk_server_cb(undefined4 param_1,int param_2,int param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_28 = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar4 = param_3;
  if (s_debug == 0) {
    if (param_2 == 0) {
LAB_004457ec:
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"Error: client did not send PSK identity\n");
      param_2 = iVar4;
      goto joined_r0x00445908;
    }
LAB_004456d4:
    iVar2 = (*(code *)PTR_strcmp_006a9b18)(param_2,"Client_identity");
    if (iVar2 != 0) goto LAB_004458e8;
LAB_004456f0:
    iVar2 = (*(code *)PTR_BN_hex2bn_006a70f0)(&local_28,psk_key);
    param_2 = psk_key;
joined_r0x004458d4:
    psk_key = param_2;
    if (iVar2 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"Could not convert PSK key \'%s\' to BIGNUM\n",
                 param_2);
      if (local_28 != 0) {
        (*(code *)PTR_BN_free_006a701c)();
      }
      goto LAB_00445744;
    }
    iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(local_28);
    iVar2 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar2 = iVar3 + 0xe;
    }
    if (param_4 < iVar2 >> 3) {
      uVar5 = *(undefined4 *)PTR_bio_err_006a6e3c;
      iVar2 = (*(code *)PTR_BN_num_bits_006a71f4)(local_28);
      iVar4 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar4 = iVar2 + 0xe;
      }
      (*(code *)PTR_BIO_printf_006a6e38)
                (uVar5,"psk buffer of callback is too small (%d) for key (%d)\n",param_4,iVar4 >> 3)
      ;
      (*(code *)PTR_BN_free_006a701c)(local_28);
      iVar2 = 0;
      iVar4 = param_4;
    }
    else {
      iVar2 = (*(code *)PTR_BN_bn2bin_006a7200)(local_28,param_3);
      (*(code *)PTR_BN_free_006a701c)(local_28);
      param_2 = iVar4;
      if (iVar2 < 0) goto joined_r0x00445908;
      if (s_debug != 0) {
        iVar4 = iVar2;
        (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"fetched PSK len=%d\n",iVar2);
      }
    }
  }
  else {
    (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"psk_server_cb\n");
    if (param_2 == 0) goto LAB_004457ec;
    if (s_debug == 0) goto LAB_004456d4;
    iVar4 = (*(code *)PTR_strlen_006a9a24)(param_2);
    (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"identity_len=%d identity=%s\n",iVar4,param_2);
    iVar2 = (*(code *)PTR_strcmp_006a9b18)(param_2,"Client_identity");
    if (iVar2 == 0) {
      if (s_debug == 0) goto LAB_004456f0;
      (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"PSK client identity found\n");
      iVar2 = (*(code *)PTR_BN_hex2bn_006a70f0)(&local_28,psk_key);
      param_2 = psk_key;
      goto joined_r0x004458d4;
    }
LAB_004458e8:
    (*(code *)PTR_BIO_printf_006a6e38)
              (bio_s_out,"PSK error: client identity not found (got \'%s\' expected \'%s\')\n",
               param_2,"Client_identity");
joined_r0x00445908:
    if (s_debug == 0) {
LAB_00445744:
      iVar2 = 0;
      iVar4 = param_2;
    }
    else {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"Error in PSK server callback\n");
      iVar2 = 0;
      iVar4 = param_2;
    }
  }
  if (local_24 == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (rsa_tmp_19388 != 0) {
    return rsa_tmp_19388;
  }
  iVar2 = (*(code *)PTR_BN_new_006a71b4)();
  puVar1 = PTR_bio_err_006a6e3c;
  if (iVar2 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"Allocation error in generating RSA key\n");
    return rsa_tmp_19388;
  }
  if (rsa_tmp_19388 != 0) {
    return rsa_tmp_19388;
  }
  if (s_quiet == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"Generating temp (%d bit) RSA key...",iVar4);
    (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar1,0xb,0,0);
  }
  iVar3 = (*(code *)PTR_BN_set_word_006a7730)(iVar2,0x10001);
  if (iVar3 == 0) {
LAB_00445a48:
    if (rsa_tmp_19388 != 0) {
      (*(code *)PTR_RSA_free_006a7600)();
    }
  }
  else {
    rsa_tmp_19388 = (*(code *)PTR_RSA_new_006a787c)();
    if (rsa_tmp_19388 != 0) {
      iVar4 = (*(code *)PTR_RSA_generate_key_ex_006a7734)(rsa_tmp_19388,iVar4,iVar2,0);
      if (iVar4 != 0) goto LAB_00445a68;
      goto LAB_00445a48;
    }
  }
  rsa_tmp_19388 = 0;
LAB_00445a68:
  puVar1 = PTR_bio_err_006a6e3c;
  if (s_quiet == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"\n");
    (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar1,0xb,0,0);
  }
  (*(code *)PTR_BN_free_006a701c)(iVar2);
  return rsa_tmp_19388;
}

