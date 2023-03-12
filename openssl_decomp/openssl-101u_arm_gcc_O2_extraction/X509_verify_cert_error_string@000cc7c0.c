
char * X509_verify_cert_error_string(long n)

{
  switch(n) {
  case 0:
    return "ok";
  default:
    BIO_snprintf(&buf_15041,100,"error number %ld",n);
    return &buf_15041;
  case 2:
    return "unable to get issuer certificate";
  case 3:
    return "unable to get certificate CRL";
  case 4:
    return "unable to decrypt certificate\'s signature";
  case 5:
    return "unable to decrypt CRL\'s signature";
  case 6:
    return "unable to decode issuer public key";
  case 7:
    return "certificate signature failure";
  case 8:
    return "CRL signature failure";
  case 9:
    return "certificate is not yet valid";
  case 10:
    return "certificate has expired";
  case 0xb:
    return "CRL is not yet valid";
  case 0xc:
    return "CRL has expired";
  case 0xd:
    return "format error in certificate\'s notBefore field";
  case 0xe:
    return "format error in certificate\'s notAfter field";
  case 0xf:
    return "format error in CRL\'s lastUpdate field";
  case 0x10:
    return "format error in CRL\'s nextUpdate field";
  case 0x11:
    return "out of memory";
  case 0x12:
    return "self signed certificate";
  case 0x13:
    return "self signed certificate in certificate chain";
  case 0x14:
    return "unable to get local issuer certificate";
  case 0x15:
    return "unable to verify the first certificate";
  case 0x16:
    return "certificate chain too long";
  case 0x17:
    return "certificate revoked";
  case 0x18:
    return "invalid CA certificate";
  case 0x19:
    return "path length constraint exceeded";
  case 0x1a:
    return "unsupported certificate purpose";
  case 0x1b:
    return "certificate not trusted";
  case 0x1c:
    return "certificate rejected";
  case 0x1d:
    return "subject issuer mismatch";
  case 0x1e:
    return "authority and subject key identifier mismatch";
  case 0x1f:
    return "authority and issuer serial number mismatch";
  case 0x20:
    return "key usage does not include certificate signing";
  case 0x21:
    return "unable to get CRL issuer certificate";
  case 0x22:
    return "unhandled critical extension";
  case 0x23:
    return "key usage does not include CRL signing";
  case 0x24:
    return "unhandled critical CRL extension";
  case 0x25:
    return "invalid non-CA certificate (has CA markings)";
  case 0x26:
    return "proxy path length constraint exceeded";
  case 0x27:
    return "key usage does not include digital signature";
  case 0x28:
    return "proxy certificates not allowed, please set the appropriate flag";
  case 0x29:
    return "invalid or inconsistent certificate extension";
  case 0x2a:
    return "invalid or inconsistent certificate policy extension";
  case 0x2b:
    return "no explicit policy";
  case 0x2c:
    return "Different CRL scope";
  case 0x2d:
    return "Unsupported extension feature";
  case 0x2e:
    return "RFC 3779 resource not subset of parent\'s resources";
  case 0x2f:
    return "permitted subtree violation";
  case 0x30:
    return "excluded subtree violation";
  case 0x31:
    return "name constraints minimum and maximum not supported";
  case 0x32:
    return "application verification failure";
  case 0x33:
    return "unsupported name constraint type";
  case 0x34:
    return "unsupported or invalid name constraint syntax";
  case 0x35:
    return "unsupported or invalid name syntax";
  case 0x36:
    return "CRL path validation error";
  case 0x41:
    return "Invalid certificate verification context";
  case 0x42:
    return "Issuer certificate lookup error";
  case 0x43:
    return "proxy subject name violation";
  }
}

