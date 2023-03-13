
evp_pkey_st * SSL_get_privatekey(SSL *ssl)

{
  if ((int *)ssl->cert != (int *)0x0) {
    return *(evp_pkey_st **)(*(int *)ssl->cert + 4);
  }
  return (evp_pkey_st *)0x0;
}

