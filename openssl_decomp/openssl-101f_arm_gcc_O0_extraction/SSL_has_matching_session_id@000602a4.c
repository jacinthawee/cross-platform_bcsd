
int SSL_has_matching_session_id(SSL *ssl,uchar *id,uint id_len)

{
  int iVar1;
  int local_110 [17];
  uint local_cc;
  undefined auStack_c8 [172];
  int local_1c;
  
  if (0x20 < id_len) {
    ssl = (SSL *)0x0;
  }
  local_1c = __TMC_END__;
  if (id_len < 0x21) {
    iVar1 = ssl->version;
    local_110[0] = iVar1;
    local_cc = id_len;
    __memcpy_chk(auStack_c8,id,id_len,0xac);
    if ((iVar1 == 2) && (id_len < 0x10)) {
      memset(auStack_c8 + id_len,0,0x10 - id_len);
      local_cc = 0x10;
    }
    CRYPTO_lock(5,0xc,"ssl_lib.c",0x1d5);
    ssl = (SSL *)lh_retrieve(*(_LHASH **)(ssl->psk_server_callback + 0x10),local_110);
    CRYPTO_lock(6,0xc,"ssl_lib.c",0x1d7);
    if (ssl != (SSL *)0x0) {
      ssl = (SSL *)0x1;
    }
  }
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)ssl;
}

