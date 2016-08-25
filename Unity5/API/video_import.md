### 2016.06

#### MovieTexture 사용 방법

[원본링크](http://qiita.com/nakfiv/items/ce7c5506c66280014709)
[유니티 레퍼런스](http://docs.unity3d.com/kr/current/Manual/class-MovieTexture.html)

동연상 파일 임포트 시 자동변환되고, 변환 시 윈도우에서는 QuickTime이 
필요하니 설치하라고 하지만 업데이트 중지로 인해 사실상 사용불가


*사용방법*

1. 동영상 데이터 준비

    MovieTexture는 실제로 ogv로 재생을 하기 때문에 Unity에 의한 변환을
    사용하지 않고 미리 ogv를 준비하여 사용합니다.
    ffmpeg로 변환가능
    [ffmpeg](https://ffmpeg.zeranoe.com/builds/)
    
    ffmpeg -y -i "title.mp4" -b 8M -ab 128k "title.ogv"

2. 재생

    public MovieTexture MovieAsset;

    void Play()
    {
        Renderer renderer = GetComponent<Renderer>();

        Material mat = new Material(Shader.Find("Unlit/Texture"));
        mat.mainTexture = MovieAsset;

        renderer.material = mat;
        
        MovieAsset.Play();
    }

