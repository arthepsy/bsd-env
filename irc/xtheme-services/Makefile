# Created by: moo@arthepsy.eu
# $FreeBSD$

PORTNAME=	xtheme-services
PORTVERSION=	7.3.3
CATEGORIES=	irc
MASTER_SITES=	https://github.com/XthemeOrg/Xtheme/releases/download/${PORTVERSION}/
DISTNAME=	Xtheme-${PORTVERSION}

MAINTAINER=	moo@arthepsy.eu
COMMENT=	Xtheme IRC Services

CONFLICTS=	atheme-services-*

USES=		pkgconfig pathfix gmake tar:bzip2

PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fhs-paths \
		--with-libmowgli=no \
		--sysconfdir=${PREFIX}/etc/xtheme \
		--localstatedir=/var
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USERS=		ircservices
GROUPS=		ircservices

USE_RC_SUBR=	xtheme-services

OPTIONS_DEFINE=	CONTRIB CRACKLIB DOCS LARGENET LDAP NLS PCRE PERL QR
OPTIONS_DEFAULT=	CRACKLIB DOCS               NLS PCRE PERL

CONTRIB_DESC=	Enable contrib modules
CRACKLIB_DESC=	Use cracklib for checking password strength
LARGENET_DESC=	Enable large network support
QR_DESC=	QR code support

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCONTRIB}
CONFIGURE_ARGS+=	--enable-contrib
.else
CONFIGURE_ARGS+=	--disable-contrib
.endif

.if ${PORT_OPTIONS:MCRACKLIB}
LIB_DEPENDS+=	libcrack.so:${PORTSDIR}/security/cracklib
CONFIGURE_ARGS+=	--with-cracklib
.else
CONFIGURE_ARGS+=	--without-cracklib
.endif

.if ${PORT_OPTIONS:MLARGENET}
CONFIGURE_ARGS+=	--enable-large-net
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-pcre
.else
CONFIGURE_ARGS+=	--without-pcre
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
CONFIGURE_ARGS+=	--with-perl
.else
CONFIGURE_ARGS+=	--without-perl
.endif

.if ${PORT_OPTIONS:MQR}
LIB_DEPENDS+=	libqrencode.so:${PORTSDIR}/graphics/libqrencode
#.else
#CONFIGURE_ENV+= LIBQRENCODE_CFLAGS=-I/nonexistent LIBQRENCODE_LIBS=-L/nonexistent
.endif

post-extract:
	@${ECHO_CMD} '#define SERNO "8299128"' > ${WRKSRC}/include/serno.h

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/etc/xtheme/xtheme.motd
	@${RMDIR} ${STAGEDIR}/var/lib/xtheme
	@${RMDIR} ${STAGEDIR}/var/lib
	@${RMDIR} ${STAGEDIR}/var/log/xtheme
	@${RMDIR} ${STAGEDIR}/var/run/xtheme
.if !${PORT_OPTIONS:MDOCS}
	@${RM} -Rf ${STAGEDIR}${PREFIX}/share/doc/xtheme
.endif

.include <bsd.port.mk>
