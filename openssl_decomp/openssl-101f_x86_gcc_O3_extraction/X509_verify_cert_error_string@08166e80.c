
char * X509_verify_cert_error_string(long n)

{
  undefined1 *puVar1;
  
  switch(n) {
  case 0:
    puVar1 = "ok";
    break;
  default:
    BIO_snprintf(buf_12380,100,"error number %ld",n);
    puVar1 = buf_12380;
    break;
  case 2:
    puVar1 = "unable to get issuer certificate";
    break;
  case 3:
    puVar1 = "unable to get certificate CRL";
    break;
  case 4:
    puVar1 = "unable to decrypt certificate\'s signature";
    break;
  case 5:
    puVar1 = "unable to decrypt CRL\'s signature";
    break;
  case 6:
    puVar1 = "unable to decode issuer public key";
    break;
  case 7:
    puVar1 = "certificate signature failure";
    break;
  case 8:
    puVar1 = "CRL signature failure";
    break;
  case 9:
    puVar1 = "certificate is not yet valid";
    break;
  case 10:
    puVar1 = "certificate has expired";
    break;
  case 0xb:
    puVar1 = "CRL is not yet valid";
    break;
  case 0xc:
    puVar1 = "CRL has expired";
    break;
  case 0xd:
    puVar1 = "format error in certificate\'s notBefore field";
    break;
  case 0xe:
    puVar1 = "format error in certificate\'s notAfter field";
    break;
  case 0xf:
    puVar1 = "format error in CRL\'s lastUpdate field";
    break;
  case 0x10:
    puVar1 = "format error in CRL\'s nextUpdate field";
    break;
  case 0x11:
    puVar1 = "out of memory";
    break;
  case 0x12:
    puVar1 = "self signed certificate";
    break;
  case 0x13:
    puVar1 = "self signed certificate in certificate chain";
    break;
  case 0x14:
    puVar1 = "unable to get local issuer certificate";
    break;
  case 0x15:
    puVar1 = "unable to verify the first certificate";
    break;
  case 0x16:
    puVar1 = "certificate chain too long";
    break;
  case 0x17:
    puVar1 = "certificate revoked";
    break;
  case 0x18:
    puVar1 = "invalid CA certificate";
    break;
  case 0x19:
    puVar1 = "path length constraint exceeded";
    break;
  case 0x1a:
    puVar1 = "unsupported certificate purpose";
    break;
  case 0x1b:
    puVar1 = "certificate not trusted";
    break;
  case 0x1c:
    puVar1 = "certificate rejected";
    break;
  case 0x1d:
    puVar1 = "subject issuer mismatch";
    break;
  case 0x1e:
    puVar1 = "authority and subject key identifier mismatch";
    break;
  case 0x1f:
    puVar1 = "authority and issuer serial number mismatch";
    break;
  case 0x20:
    puVar1 = "key usage does not include certificate signing";
    break;
  case 0x21:
    puVar1 = "unable to get CRL issuer certificate";
    break;
  case 0x22:
    puVar1 = "unhandled critical extension";
    break;
  case 0x23:
    puVar1 = "key usage does not include CRL signing";
    break;
  case 0x24:
    puVar1 = "unhandled critical CRL extension";
    break;
  case 0x25:
    puVar1 = "invalid non-CA certificate (has CA markings)";
    break;
  case 0x26:
    puVar1 = "proxy path length constraint exceeded";
    break;
  case 0x27:
    puVar1 = "key usage does not include digital signature";
    break;
  case 0x28:
    puVar1 = "proxy certificates not allowed, please set the appropriate flag";
    break;
  case 0x29:
    puVar1 = "invalid or inconsistent certificate extension";
    break;
  case 0x2a:
    puVar1 = "invalid or inconsistent certificate policy extension";
    break;
  case 0x2b:
    puVar1 = "no explicit policy";
    break;
  case 0x2c:
    puVar1 = "Different CRL scope";
    break;
  case 0x2d:
    puVar1 = "Unsupported extension feature";
    break;
  case 0x2e:
    puVar1 = "RFC 3779 resource not subset of parent\'s resources";
    break;
  case 0x2f:
    puVar1 = "permitted subtree violation";
    break;
  case 0x30:
    puVar1 = "excluded subtree violation";
    break;
  case 0x31:
    puVar1 = "name constraints minimum and maximum not supported";
    break;
  case 0x32:
    puVar1 = "application verification failure";
    break;
  case 0x33:
    puVar1 = "unsupported name constraint type";
    break;
  case 0x34:
    puVar1 = "unsupported or invalid name constraint syntax";
    break;
  case 0x35:
    puVar1 = "unsupported or invalid name syntax";
    break;
  case 0x36:
    puVar1 = "CRL path validation error";
  }
  return puVar1;
}

