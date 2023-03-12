
int SSL_has_matching_session_id(SSL *ssl,uchar *id,uint id_len)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_110 [17];
  uint local_cc;
  undefined auStack_c8 [172];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar2 = 0;
  if (id_len < 0x21) {
    iVar4 = ssl->version;
    local_110[0] = iVar4;
    local_cc = id_len;
    iVar3 = (*(code *)PTR___memcpy_chk_006a9a48)(auStack_c8,id,id_len,0xac);
    if ((iVar4 == 2) && (id_len < 0x10)) {
      (*(code *)PTR_memset_006a99f4)(iVar3 + id_len,0,0x10 - id_len);
      local_cc = 0x10;
    }
    CRYPTO_lock(5,0xc,"ssl_lib.c",0x1d8);
    iVar3 = (*(code *)PTR_lh_retrieve_006a73b0)
                      (*(undefined4 *)(ssl->psk_server_callback + 0x10),local_110);
    CRYPTO_lock(6,0xc,"ssl_lib.c",0x1da);
    uVar2 = (uint)(iVar3 != 0);
  }
  if (local_1c == *(int *)puVar1) {
    return uVar2;
  }
  iVar3 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x004a70a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar3 = (*(code *)PTR_X509_VERIFY_PARAM_set_purpose_006a7c0c)(*(undefined4 *)(iVar3 + 0xf0));
  return iVar3;
}

