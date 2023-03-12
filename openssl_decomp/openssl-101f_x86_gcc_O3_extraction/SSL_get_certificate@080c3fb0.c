
X509 * SSL_get_certificate(SSL *ssl)

{
  if ((undefined4 *)ssl->cert != (undefined4 *)0x0) {
    return **(X509 ***)ssl->cert;
  }
  return (X509 *)0x0;
}

