
int SSL_has_matching_session_id(SSL *ssl,uchar *id,uint id_len)

{
  int iVar1;
  uint uVar2;
  void *mode;
  uint uVar3;
  undefined4 *puVar4;
  int in_GS_OFFSET;
  int local_114 [17];
  uint local_d0;
  undefined4 local_cc;
  undefined auStack_c8 [8];
  undefined4 uStack_c0;
  undefined auStack_bc [156];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar2 = 0;
  if (id_len < 0x21) {
    iVar1 = ssl->version;
    local_d0 = id_len;
    local_114[0] = iVar1;
    uVar2 = __memcpy_chk(&local_cc,id,id_len,0xac);
    if ((id_len < 0x10) && (iVar1 == 2)) {
      uVar2 = 0x10 - id_len;
      puVar4 = (undefined4 *)((int)&local_cc + id_len);
      if (uVar2 < 4) {
        if ((uVar2 != 0) && (*(undefined *)puVar4 = 0, (uVar2 & 2) != 0)) {
          *(undefined2 *)((int)&uStack_c0 + uVar2 + id_len + -0xe) = 0;
        }
      }
      else {
        *puVar4 = 0;
        *(undefined4 *)((int)&uStack_c0 + uVar2 + id_len + -0x10) = 0;
        uVar2 = (uint)((int)puVar4 + (uVar2 - ((uint)(auStack_c8 + id_len) & 0xfffffffc))) &
                0xfffffffc;
        if (3 < uVar2) {
          uVar3 = 0;
          do {
            *(undefined4 *)(((uint)(auStack_c8 + id_len) & 0xfffffffc) + uVar3) = 0;
            uVar3 = uVar3 + 4;
          } while (uVar3 < uVar2);
        }
      }
      local_d0 = 0x10;
    }
    CRYPTO_lock(uVar2,5,&DAT_0000000c,(int)"ssl_lib.c");
    mode = lh_retrieve(*(_LHASH **)(ssl->psk_server_callback + 0x10),local_114);
    CRYPTO_lock((int)mode,6,&DAT_0000000c,(int)"ssl_lib.c");
    uVar2 = (uint)(mode != (void *)0x0);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

