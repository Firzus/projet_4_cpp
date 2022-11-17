class Button
{
public:
    SDL_Texture *text;
    SDL_Rect srect, drect;
    bool isSelected = false;

    Button();
    virtual ~Button();

    void update(Mouse &);
}