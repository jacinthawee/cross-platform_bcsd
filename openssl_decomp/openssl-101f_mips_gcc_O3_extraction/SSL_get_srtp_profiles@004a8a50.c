
stack_st_SRTP_PROTECTION_PROFILE * SSL_get_srtp_profiles(SSL *ssl)

{
  if (ssl == (SSL *)0x0) {
    return (stack_st_SRTP_PROTECTION_PROFILE *)0x0;
  }
  if ((*(stack_st_SRTP_PROTECTION_PROFILE **)&ssl->next_proto_negotiated_len ==
       (stack_st_SRTP_PROTECTION_PROFILE *)0x0) && (ssl->psk_server_callback != (_func_3154 *)0x0))
  {
    return *(stack_st_SRTP_PROTECTION_PROFILE **)(ssl->psk_server_callback + 0x1b4);
  }
  return *(stack_st_SRTP_PROTECTION_PROFILE **)&ssl->next_proto_negotiated_len;
}

