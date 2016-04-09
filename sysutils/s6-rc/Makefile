# Created by: Andris Raugulis <moo@arthepsy.eu>
# $FreeBSD$

PORTNAME=	s6-rc
PORTVERSION=	0.0.2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	moo@arthepsy.eu
COMMENT=	skarnet.org service manager

LICENSE=	ISCL

BUILD_DEPENDS=	skalibs>=2.3.8.3:devel/skalibs \
		execline>=2.1.4.5:lang/execline \
		s6>=2.2.4.2:sysutils/s6
RUN_DEPENDS=	execlineb:lang/execline

USES=		gmake

USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} \
	--with-include=${LOCALBASE}/include \
	--with-lib=${LOCALBASE}/lib/skalibs \
	--with-lib=${LOCALBASE}/lib/execline \
	--with-lib=${LOCALBASE}/lib/s6 \
	--with-dynlib=${LOCALBASE}/lib \
	--enable-shared

DOCS=		AUTHORS COPYING INSTALL README doc/*.html
OPTIONS_DEFINE=	DOCS

post-install:
.for d in bin sbin libexec
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${d}/*
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libs6rc.so.${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
