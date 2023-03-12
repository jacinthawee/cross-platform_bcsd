
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_28 = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar4 = param_3;
  if (s_debug == 0) {
    if (param_2 == 0) {
LAB_004451b4:
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"Error: client did not send PSK identity\n");
    }
    else {
LAB_0044509c:
      iVar2 = (*(code *)PTR_strcmp_006aac20)(param_2,"Client_identity");
      if (iVar2 == 0) goto LAB_004450b8;
LAB_00445290:
      (*(code *)PTR_BIO_printf_006a7f38)
                (bio_s_out,"PSK error: client identity not found (got \'%s\' expected \'%s\')\n",
                 param_2,"Client_identity");
      iVar4 = param_2;
    }
joined_r0x004452b0:
    if (s_debug == 0) {
LAB_0044510c:
      iVar2 = 0;
    }
    else {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"Error in PSK server callback\n");
      iVar2 = 0;
    }
  }
  else {
    (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out,"psk_server_cb\n");
    if (param_2 == 0) goto LAB_004451b4;
    if (s_debug == 0) goto LAB_0044509c;
    iVar4 = (*(code *)PTR_strlen_006aab30)(param_2);
    (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out,"identity_len=%d identity=%s\n",iVar4,param_2);
    iVar2 = (*(code *)PTR_strcmp_006aac20)(param_2,"Client_identity");
    if (iVar2 != 0) goto LAB_00445290;
    if (s_debug != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out,"PSK client identity found\n");
    }
LAB_004450b8:
    iVar2 = (*(code *)PTR_BN_hex2bn_006a81f0)(&local_28,psk_key);
    if (iVar2 == 0) {
      iVar4 = psk_key;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"Could not convert PSK key \'%s\' to BIGNUM\n",
                 psk_key);
      if (local_28 != 0) {
        (*(code *)PTR_BN_free_006a811c)();
      }
      goto LAB_0044510c;
    }
    iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(local_28);
    iVar2 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar2 = iVar3 + 0xe;
    }
    if (param_4 < iVar2 >> 3) {
      uVar5 = *(undefined4 *)PTR_bio_err_006a7f3c;
      iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(local_28);
      iVar4 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar4 = iVar2 + 0xe;
      }
      (*(code *)PTR_BIO_printf_006a7f38)
                (uVar5,"psk buffer of callback is too small (%d) for key (%d)\n",param_4,iVar4 >> 3)
      ;
      (*(code *)PTR_BN_free_006a811c)(local_28);
      iVar2 = 0;
      iVar4 = param_4;
    }
    else {
      iVar2 = (*(code *)PTR_BN_bn2bin_006a8300)(local_28,param_3);
      (*(code *)PTR_BN_free_006a811c)(local_28);
      if (iVar2 < 0) goto joined_r0x004452b0;
      if (s_debug != 0) {
        iVar4 = iVar2;
        (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out,"fetched PSK len=%d\n",iVar2);
      }
    }
  }
  if (local_24 == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (rsa_tmp_19390 != 0) {
    return rsa_tmp_19390;
  }
  iVar2 = (*(code *)PTR_BN_new_006a82b4)();
  puVar1 = PTR_bio_err_006a7f3c;
  if (iVar2 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"Allocation error in generating RSA key\n");
    return rsa_tmp_19390;
  }
  if (rsa_tmp_19390 != 0) {
    return rsa_tmp_19390;
  }
  if (s_quiet == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"Generating temp (%d bit) RSA key...",iVar4);
    (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar1,0xb,0,0);
  }
  iVar3 = (*(code *)PTR_BN_set_word_006a8820)(iVar2,0x10001);
  if (iVar3 == 0) {
LAB_004453f0:
    if (rsa_tmp_19390 != 0) {
      (*(code *)PTR_RSA_free_006a86f0)();
    }
  }
  else {
    rsa_tmp_19390 = (*(code *)PTR_RSA_new_006a8964)();
    if (rsa_tmp_19390 != 0) {
      iVar4 = (*(code *)PTR_RSA_generate_key_ex_006a8824)(rsa_tmp_19390,iVar4,iVar2,0);
      if (iVar4 != 0) goto LAB_00445410;
      goto LAB_004453f0;
    }
  }
  rsa_tmp_19390 = 0;
LAB_00445410:
  puVar1 = PTR_bio_err_006a7f3c;
  if (s_quiet == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,"\n");
    (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar1,0xb,0,0);
  }
  (*(code *)PTR_BN_free_006a811c)(iVar2);
  return rsa_tmp_19390;
}

