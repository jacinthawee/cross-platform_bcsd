
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar2 = 0;
  if (id_len < 0x21) {
    iVar4 = ssl->version;
    local_110[0] = iVar4;
    local_cc = id_len;
    iVar3 = (*(code *)PTR___memcpy_chk_006aab54)(auStack_c8,id,id_len,0xac);
    if ((iVar4 == 2) && (id_len < 0x10)) {
      (*(code *)PTR_memset_006aab00)(iVar3 + id_len,0,0x10 - id_len);
      local_cc = 0x10;
    }
    CRYPTO_lock(5,0xc,"ssl_lib.c",0x1d5);
    iVar3 = (*(code *)PTR_lh_retrieve_006a84b0)
                      (*(undefined4 *)(ssl->psk_server_callback + 0x10),local_110);
    CRYPTO_lock(6,0xc,"ssl_lib.c",0x1d7);
    uVar2 = (uint)(iVar3 != 0);
  }
  if (local_1c == *(int *)puVar1) {
    return uVar2;
  }
  iVar3 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x004a9e98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar3 = (*(code *)PTR_X509_VERIFY_PARAM_set_purpose_006a8cf8)(*(undefined4 *)(iVar3 + 0xf0));
  return iVar3;
}

